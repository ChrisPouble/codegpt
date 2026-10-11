#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int n, m, tot, cnt;
int vis[N], a[N], b[N], sum, mid;
// b[i] 表示以 i 为根的子树中，所有以 u 为起点的链中没有达到 mid 的链或者不能与另一条没有达到 mid 的链拼在一起来超过 mid 的链中最长的那条链的长度
// a[] 负责记录所有 b_v + w < mid 的数
// vis 表示标记

struct edge {
    int to, w;
};

vector<edge> linker[N];

void add(int x, int y, int w) {
    linker[x].push_back({ y, w });
}

void dfs(int u, int fa) {
    for (auto i : linker[u]) {
        int v = i.to;
        if (v != fa) dfs(v, u);
    }
    
    cnt = 0;
    for (auto i : linker[u]) {
        int v = i.to;
        int w = i.w;

        if (v != fa) {
            if (b[v] + w >= mid) ++tot;
            else a[++cnt] = b[v] + w;
        }
    }
    
    sort(a + 1, a + cnt + 1);
    memset(vis, 0, sizeof(vis));
    
    for (int i = 1; i <= cnt; ++i) {
        if (vis[i]) continue;
        int j = lower_bound(a + i + 1, a + cnt + 1, mid - a[i]) - a;
        if (j == cnt + 1) continue;

        while (j <= cnt && vis[j]) ++j;
        if (j <= cnt && !vis[j] && a[i] + a[j] >= mid) {
            vis[i] = vis[j] = 1;
            ++tot;
        }
    }
    
    b[u] = 0;
    for (int i = 1; i <= cnt; ++i)
        if (!vis[i]) b[u] = a[i];
}

bool check() {
    tot = 0;
    dfs(1, 0);
    return tot >= m;
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }
        
    int l = 0, r = 1e9, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (check()) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}