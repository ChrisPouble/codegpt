#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int M = 1e7 + 10;

struct edge {
	int to, w;
};

int n, m, u, v, w;
int k[N], ans[N], dep[N], sz[N], mxs[N];
int rt, sta[N], top;
bool del[N], tp[M];
vector <edge> linker[N];

void dfs_init_dep(int u, int fa) {
    for (auto p : linker[u]) {
        int v = p.to, w = p.w;
        if (!del[v] && v != fa) {
            dep[v] = dep[u] + w;
            dfs_init_dep(v, u);
        }
    }
}

void dfs_init_sz(int u, int fa, int S) {
    sz[u] = 1, mxs[u] = 0;
    for (auto p : linker[u]) {
        int v = p.to;
        if (!del[v] && v != fa) {
            dfs_init_sz(v, u, S);
            sz[u] += sz[v], mxs[u] = max(mxs[u], sz[v]);
        }
    }
	mxs[u] = max(mxs[u], S - sz[u]);
    if (mxs[rt] > mxs[u]) rt = u;
}

void dfs_check(int u, int fa) {
    for (int i = 1; i <= m; i++)
		if (dep[u] <= k[i] && tp[k[i] - dep[u]])
            ans[i] = 1;
	
    sta[++top] = u;
    for (auto p : linker[u]) {
        int v = p.to;
        if (!del[v] && v != fa)
            dfs_check(v, u);
    }
}

void solve(int u, int S) {
	// 初始化 
    rt = 0, mxs[0] = 1e9, dfs_init_sz(u, 0, S);
    for (; top; top--) {
        if (dep[sta[top]] < M)
            tp[dep[sta[top]]] = 0;
    }
    del[rt] = 1, tp[0] = 1, dep[rt] = 0, dfs_init_dep(rt, 0);
    
    for (auto p : linker[rt]) {
        int v = p.to; if (del[v]) continue;

        int lst = top; dfs_check(v, 0);
        for (int i = lst + 1; i <= top; i++)
			if (dep[sta[i]] < M) tp[dep[sta[i]]] = 1;
    }
    
    for (auto p : linker[rt]) {
        int v = p.to;
        if (!del[v]) solve(v, u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
		linker[u].push_back({ v, w });
		linker[v].push_back({ u, w });
    }

    for (int i = 1; i <= m; i++)
        cin >> k[i];

    solve(1, n);
    for (int i = 1; i <= m; i++)
        puts(ans[i] ? "AYE" : "NAY");
    
    return 0;
}