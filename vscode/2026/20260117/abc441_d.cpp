#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;

struct edge {
    int v, w;
};

int n, m, L, s, t;
int vis[N];
vector<edge> linker[N];

void dfs(int u, int dep, int cost) {
    if (cost > t) return ;

    if (dep == L) {
        if (cost >= s) vis[u] = 1;
        return ;
    }

    for (auto i : linker[u]) {
        dfs(i.v, dep + 1, cost + i.w);
    }
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> L >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        linker[u].push_back({v, w});
    }

    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++)
        if (vis[i]) cout << i << " ";
	
	return 0;
}
