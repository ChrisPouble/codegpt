#include <bits/stdc++.h>
using namespace std;

static const int B = 18;  // 值域位数：2e5 < 2^18
static const int MAXV = (1 << B) - 1;

struct Node {
    int lc, rc;   // 左右子
    int cnt;      // 覆盖元素个数
    int ones[B];  // 每一位上 1 的个数
};
vector<Node> T;    // 持久化分段树所有节点
vector<int> root;  // 每个前缀的根

int newnode(int from = 0) {
    T.push_back(T[from]);  // 克隆
    return (int)T.size() - 1;
}

int update(int pre, int l, int r, int val) {
    int cur = newnode(pre);
    T[cur].cnt = T[pre].cnt + 1;
    // 把该值的每一位贡献 +1
    for (int b = 0; b < B; ++b)
        if ((val >> b) & 1)
            ++T[cur].ones[b];

    if (l == r)
        return cur;
    int mid = (l + r) >> 1;
    if (val <= mid) {
        T[cur].lc = update(T[pre].lc, l, mid, val);
        // 右儿子沿用
    } else {
        T[cur].rc = update(T[pre].rc, mid + 1, r, val);
    }
    return cur;
}

// 区间[L,R]由 root[R]-root[L-1] 表示
inline int cnt_of(int uR, int uL) { return T[uR].cnt - T[uL].cnt; }
inline int ones_of_b(int uR, int uL, int b) { return T[uR].ones[b] - T[uL].ones[b]; }

// 计算当前节点（表示一个值域段）内所有元素的 sum(v XOR f)
int sumXorAll(int uR, int uL, int f) {
    int c = cnt_of(uR, uL);
    int s = 0;
    for (int b = 0; b < B; ++b) {
        int cnt1 = ones_of_b(uR, uL, b);
        int take1 = ((f >> b) & 1) ? (c - cnt1) : cnt1;  // 该位对 XOR 为 1 的个数
        s += (1LL << b) * take1;
    }
    return s;
}

// 取区间的前 k 大 (v XOR f) 的总和
int topK_sum(int uR, int uL, int f, int k) {
    int ans = 0;
    int l = 0, r = MAXV;
    int curR = uR, curL = uL;
    int val = 0;

    for (int b = B - 1; b >= 0; --b) {
        int mid = (l + r) >> 1;
        // 偏好分支：希望 XOR 的该位为 1
        int pref = ((f >> b) & 1) ^ 1;  // 1^f_b
        int uR_pref = pref ? T[curR].rc : T[curR].lc;
        int uL_pref = pref ? T[curL].rc : T[curL].lc;
        int pc = cnt_of(uR_pref, uL_pref);

        if (pc >= k) {
            // 进入偏好分支
            if (pref) {
                l = mid + 1;
                val |= (1 << b);
            } else {
                r = mid;
            }
            curR = uR_pref;
            curL = uL_pref;
        } else {
            // 把偏好分支整个吃掉
            if (pc > 0)
                ans += sumXorAll(uR_pref, uL_pref, f);
            k -= pc;
            // 转到另一分支
            int oth = pref ^ 1;
            int uR_oth = oth ? T[curR].rc : T[curR].lc;
            int uL_oth = oth ? T[curL].rc : T[curL].lc;

            if (oth) {
                l = mid + 1;
                val |= (1 << b);
            } else {
                r = mid;
            }
            curR = uR_oth;
            curL = uL_oth;
        }
    }
    // 走到叶子，剩余的 k（<= 该叶计数），它们的 XOR 值相同
    if (k > 0) {
        ans += 1LL * k * ((val ^ f));
    }
    return ans;
}

// —— 树与 Euler —— //
const int MAXN = 100000 + 5;
int n, m;
vector<int> g[MAXN];
int a[MAXN];
int tin[MAXN], tout[MAXN], euler_to_node[MAXN], timer_dfs = 0;

void dfs(int u) {
    tin[u] = ++timer_dfs;
    euler_to_node[timer_dfs] = u;
    for (int v : g[u]) dfs(v);
    tout[u] = timer_dfs;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int id;
    if (!(cin >> id >> n >> m))
        return 0;

    for (int i = 1; i <= n; ++i) cin >> a[i];
    // 父亲 p_{i+1}，i=1..n-1，根为 1
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    // Euler 序
    dfs(1);

    // 初始化持久化结构
    T.reserve((size_t)n * (B + 2) + 10);
    T.push_back(Node());  // 0 号空节点
    root.resize(n + 1);
    root[0] = 0;

    // 依 Euler 序插入
    for (int i = 1; i <= n; ++i) {
        int val = a[euler_to_node[i]];
        root[i] = update(root[i - 1], 0, MAXV, val);
    }

    // 处理询问
    while (m--) {
        int k, x, f;
        cin >> k >> x >> f;
        int L = tin[x], R = tout[x];
        int ans = topK_sum(root[R], root[L - 1], f, k);
        cout << ans << '\n';
    }
    system("pause");
    return 0;
}
/*
1 5 5
 4 4 2 2 1
 1 1 2 2
 1 1 4
 1 2 5
 3 1 4
 3 2 4
 1 2 5
*/