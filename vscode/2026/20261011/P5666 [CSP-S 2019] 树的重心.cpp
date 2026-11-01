#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 10;

int n;
vector<int> linker[N];

int sz[N], rt;
int s[N], g[N];
int tree1[N], tree2[N];
ll ans;
int max_u, max_v;

int lowbit(int x) { return x & -x; }

void add(int *tree, int x, int k) {
    if (x <= 0) return ;
    while (x <= n) { tree[x] += k, x += lowbit(x); }
}

int ask(int *tree, int x) {
    if (x <= 0) return 0;
    if (x > n) x = n;

    int sum = 0;
    while (x) { sum += tree[x], x -= lowbit(x); }
    return sum;
}

void get_rt(int x, int fa) {
    sz[x] = 1; int mx = 0;
    for (int v : linker[x]) {
        if (v == fa) continue;
        get_rt(v, x);

        sz[x] += sz[v];
        mx = max(mx, sz[v]);
    }

    mx = max(mx, n - sz[x]);
    if (mx <= n / 2) rt = x;
}

void dfs_rt(int x, int fa) {
    s[x] = 1, g[x] = 0;
    for (int v : linker[x]) {
        if (v == fa) continue;
        dfs_rt(v, x);

        s[x] += s[v];
        g[x] = max(g[x], s[v]);
    }
}

// belong 记录当前节点属于重心 rt 的哪一棵子树（用于特判 rt）
void dfs_find(int x, int fa, int belong) {
    // 当视线向深处移动到 x，原本的 sz 变成了 n - sz
    if (x != rt) {
        add(tree1, s[x], -1);
        add(tree1, n - s[x], 1);
    }
    
    int L = 0, R = -1;
    int pre = 0;

    if (x != rt) {
        L = max(1, n - 2 * s[x]);
        R = n - 2 * g[x];
        if (L <= R) {
            // 查询合法的割边总数
            ans += (ll)x * (ask(tree1, R) - ask(tree1, L - 1));
            // 进入子树前，记录树状数组 c2 的状态
            pre = ask(tree2, R) - ask(tree2, L - 1);
        }
    }
    
    for (int v : linker[x]) {
        if (v == fa) continue;
        dfs_find(v, x, x == rt ? v : belong);
    }
    
    if (x == rt) return ;

    if (L <= R) {
        // 离开子树后查询差值，即减去在自身子树内部的不合法割边
        int post = ask(tree2, R) - ask(tree2, L - 1);
        ans -= (ll)x * (post - pre);
    }
    
    // 状态回溯
    add(tree1, n - s[x], -1);
    add(tree1, s[x], 1);
    add(tree2, s[x], 1); // 把自己加入到 tree2，给祖先去重
    
    // 判断当前割掉 (x, fa) 这条边，原重心 rt 能否继续担任新树重心
    if (belong == max_u) {
        if (s[x] <= n - 2 * s[max_v]) ans += rt;
    } else {
        if (s[x] <= n - 2 * s[max_u]) ans += rt;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        linker[i].clear();
        tree1[i] = tree2[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }
    
    rt = 0, get_rt(1, 0);
    dfs_rt(rt, 0);
    
    max_u = 0; max_v = 0;
    s[0] = 0;
    
    for (int v : linker[rt]) {
        if (s[v] > s[max_u]) {
            max_v = max_u;
            max_u = v;
        } else if (s[v] > s[max_v]) {
            max_v = v;
        }
    }
    
    // 初始化树状数组 c1
    for (int i = 1; i <= n; i++) {
        if (i != rt) add(tree1, s[i], 1);
    }
    
    ans = 0;
    dfs_find(rt, 0, 0);
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}