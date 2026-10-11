#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 2e5 + 10;

int n, m, q, tot, a[M];
int dfn[M * 2], low[M * 2];
int stk[M * 2];

vector <int> linker[M], G[M * 2];

int top, tp;
void Tarjan(int u) {
	low[u] = dfn[u] = ++top;
	stk[++tp] = u;
	for (int v : linker[u]) {
		if (!dfn[v]) {
			Tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] == dfn[u]) {
				++tot;
				for (int x = 0; x != v; --tp) {
					x = stk[tp];
					G[tot].push_back(x);
					G[x].push_back(tot);
				}
				G[tot].push_back(u);
				G[u].push_back(tot);
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}

int tnt, father[M * 2][25];
int sum[M * 2], dep[M * 2];
int gfn[M * 2], dis[M * 2];

void gfs(int x, int f) {
    gfn[x] = ++tnt;
	dep[x] = dep[f] + 1;
	father[x][0] = f;
	
	for (auto v : G[x]) {		
		if (v == f) continue;
		dis[v] = dis[x] + (x <= n), gfs(v, x);
	}
}

void init() {
	gfs(1, 0);
	for (int j = 1; (1 << j) <= tot; j++) 
		for (int i = 1; i <= tot; i++) 
			father[i][j] = father[father[i][j - 1]][j - 1];
}

int lx, ly; 
int LCA(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	
	for (int i = 17; i >= 0; i--)
		if (dep[father[x][i]] >= dep[y])
			x = father[x][i];
	
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	}
	
	lx = x, ly = y;
	return father[x][0];
}

bool cmp(int x, int y) {
    return gfn[x] < gfn[y];
}

void solve() {
    for (int i = 1; i <= n; i++) {
        linker[i].clear();
        dfn[i] = low[i] = 0;
		dis[i] = dep[i] = 0;
    }

    for (int i = 1; i <= tot; i++)
        G[i].clear();

    cin >> n >> m;
	
	tot = n;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		linker[u].push_back(v);
        linker[v].push_back(u);
	}
	
	top = tp = 0, Tarjan(1);
    tnt = 0, init();

    cin >> q;
    while (q--) {
        int S; cin >> S;
        int ans = -2 * S;

        for (int i = 1; i <= S; i++)
            cin >> a[i];

        sort(a + 1, a + S + 1, cmp);

        for (int i = 1; i < S; i++) {
            int u = a[i], v = a[i + 1];
            ans += dis[u] + dis[v] - 2 * dis[LCA(u, v)];
        }

        ans += dis[a[1]] + dis[a[S]] - 2 * dis[LCA(a[1], a[S])];
        if (LCA(a[1], a[S]) <= n) ans += 2;

        cout << ans / 2 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	int T; cin >> T;

    while (T--) solve();

	system("pause");
	return 0;
}