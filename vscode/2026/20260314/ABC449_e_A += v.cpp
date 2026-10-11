#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;

int n, m, q;

struct Node {
    int ch[2];
    int fa, val, size;
} spl[N];

int cnt, root;

void update(int x) {
    spl[x].size = spl[spl[x].ch[0]].size + spl[spl[x].ch[1]].size + 1;
}

int ident(int x, int fa) {
    return spl[fa].ch[1] == x;
}

void connect(int x, int fa, int k) {
    spl[x].fa = fa;
    spl[fa].ch[k] = x;
}

void rotate(int x) {
    int fa = spl[x].fa, ffa = spl[fa].fa, k = ident(x, fa);
    connect(spl[x].ch[k ^ 1], fa, k);
    connect(x, ffa, ident(fa, ffa));
    connect(fa, x, k ^ 1);
    update(fa);
    update(x);
}

void splaying(int x, int top) {
    if (!top) root = x;
    while (spl[x].fa != top) {
        int fa = spl[x].fa, ffa = spl[fa].fa;
        if (ffa != top) {
            ident(x, fa) ^ ident(fa, ffa) ? rotate(x) : rotate(fa);
        }
        rotate(x);
    }
}

void newnode(int &node, int fa, int val) {
    spl[node = ++cnt].val = val;
    spl[cnt].fa = fa;
    spl[cnt].size = 1;
}

void insert(int &node, int val, int fa) {
    if (!node) {
        newnode(node, fa, val);
        splaying(node, 0);
    } else if (val < spl[node].val)
        insert(spl[node].ch[0], val, node);
    else
        insert(spl[node].ch[1], val, node);
}

int query(int rk) {
    int node = root;
    while (node) {
        if (spl[spl[node].ch[0]].size + 1 == rk) {
            splaying(node, 0);
            break;
        } else if (spl[spl[node].ch[0]].size >= rk)
            node = spl[node].ch[0];
        else {
            rk -= spl[spl[node].ch[0]].size + 1;
            node = spl[node].ch[1];
        }
    }
    return spl[node].val;
}

int a[N], sum[N];
ll p[N];
int ans[N];
vector<int> linker[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[a[i]]++;
    }

    // 按初始出现次数分组（组内按值从小到大）
    for (int v = 1; v <= m; v++) {
        linker[sum[v]].push_back(v);
    }

    // 收集不同的出现次数，排序
    set<int> cnt_set;
    for (int v = 1; v <= m; v++) cnt_set.insert(sum[v]);
    vector<int> levels(cnt_set.begin(), cnt_set.end());
    int L = levels.size();

    // 计算每个有限阶段的累计追加元素数
    // 阶段 i (0 <= i < L-1): 活跃集合 = 出现次数 <= levels[i] 的所有值
    //   该阶段追加量 = 活跃集合大小 * (levels[i+1] - levels[i])
    // 阶段 L-1 (无限): 所有 M 个值按 1,2,...,M 永远循环
    vector<ll> cum(L, 0);
    vector<int> phase_sz(L, 0);
    ll total = 0;
    int active = 0;
    for (int i = 0; i < L; i++) {
        active += (int)linker[levels[i]].size();
        phase_sz[i] = active;
        if (i + 1 < L) {
            ll gap = levels[i + 1] - levels[i];
            total += (ll)active * gap;
        }
        cum[i] = total;
    }

    cin >> q;
    for (int i = 1; i <= q; i++) cin >> p[i];

    // 对每个查询，确定它落在哪个阶段、以及在活跃集合中的排名
    struct QInfo {
        int phase;  // -1 = 原数组, 0..L-1 = 各阶段
        ll rank;    // 0-indexed 在活跃集合循环中的排名
        int idx;    // 原查询编号
    };
    vector<QInfo> qs(q);

    for (int i = 0; i < q; i++) {
        ll x = p[i + 1];
        qs[i].idx = i + 1;
        if (x <= n) {
            qs[i].phase = -1;
            qs[i].rank = 0;
            ans[i + 1] = a[x];
        } else {
            ll pos = x - n - 1; // 在追加序列中的 0-indexed 位置
            // 二分找第一个 cum[j] > pos 的 j
            int lo = 0, hi = L - 2, j = L - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (cum[mid] <= pos) lo = mid + 1;
                else { j = mid; hi = mid - 1; }
            }
            qs[i].phase = j;
            ll prev = (j > 0 ? cum[j - 1] : 0);
            ll pos_in_phase = pos - prev;
            qs[i].rank = pos_in_phase % phase_sz[j];
        }
    }

    // 按阶段排序，这样可以增量构建 Splay 树
    sort(qs.begin(), qs.end(), [](const QInfo &a, const QInfo &b) {
        return a.phase < b.phase;
    });

    int qi = 0;
    // 跳过原数组查询（已直接回答）
    while (qi < q && qs[qi].phase == -1) qi++;

    // 逐阶段处理：插入新值到 Splay 树，回答该阶段的查询
    for (int i = 0; i < L && qi < q; i++) {
        for (int v : linker[levels[i]]) {
            insert(root, v, 0);
        }
        while (qi < q && qs[qi].phase == i) {
            int rk = (int)(qs[qi].rank) + 1; // 1-indexed
            ans[qs[qi].idx] = query(rk);
            qi++;
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}