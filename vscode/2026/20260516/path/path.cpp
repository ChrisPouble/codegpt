#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, q;
int fa[N], siz[N];
int id[N];                // 存储每个点的一个 0 权边邻居
vector <int> linker[N];   // 存储该点尚未被 0 权边“归并”的邻居列表

// 并查集查找（迭代版防止爆栈）
int find(int x) {
    while (x != fa[x]) {
        fa[x] = fa[fa[x]]; // 路径压缩
        x = fa[x];
    }
    return x;
}

// 并查集合并（按秩合并）
void merge(int x, int y) {
    int xx = find(x), yy = find(y);
    if (xx == yy) return;
    if (siz[xx] < siz[yy]) swap(xx, yy);
    fa[yy] = xx;
    siz[xx] += siz[yy];
}

void add(int u, int v, int w) {
    if (w == 1) {
        // 如果 u 已经有 0 权边邻居了，新邻居 v 就可以通过 u 与 id[u] 连通
        if (id[u]) merge(id[u], v);
        // 同理处理 v
        if (id[v]) merge(id[v], u);
        
        // 记录邻居，备后续 u/v 获得 0 权边时合并
        linker[u].push_back(v);
        linker[v].push_back(u);
    } else {
        // 0 权边加入时，u 之前所有的邻居都可以通过这条 0 权边与 v 连通
        for (int p : linker[u]) merge(p, v);
        for (int p : linker[v]) merge(p, u);
        
        // 更新 id：现在 u 的 0 权边邻居是 v，v 的是 u
        // 此时 linker[u] 里的旧邻居已经全部合并，只需要保留最新的 0 权邻居即可
        id[u] = v;
        id[v] = u;
        linker[u] = {v}; 
        linker[v] = {u};
    }
}

void solve() {
    cin >> n >> m >> q;
    
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
        id[i] = 0;
        linker[i].clear();
    }
    
    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    
    int opt, x, y, z;
    while (q--) {
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> z;
            add(x, y, z);
        } else {
            cin >> x >> y;
            if (find(x) == find(y)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T; cin >> T;
    solve();
    
    return 0;
}