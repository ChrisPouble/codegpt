#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 10;
const int M = 5e4 + 10; 
const int inf = 0x3f3f3f3f3f3f3f3f;

int min(int x, int y) {
	return x < y ? x : y;
}

int n, m, s, t;
int top = 1;

int head[N], cur[N];

struct node {
	int v, w, val;
	int nxt;
} edge[M * 2];

void add(int u, int v, int w, int val) {
	edge[++top] = { v, w, val };
	edge[top].nxt = head[u];
	head[u] = top;
}

int ans, cost, dis[N], vis[N];

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		cur[i] = head[i];
		vis[i] = 0, dis[i] = inf;
	}
	
	vis[s] = 1, dis[s] = 0, q.push(s);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		vis[x] = 0;
		
		// 分层 
		for (int i = head[x]; i; i = edge[i].nxt) {
			int d = edge[i].v, val = edge[i].val;
			if (dis[d] > dis[x] + val && edge[i].w) {
				dis[d] = dis[x] + val;
				if (!vis[d]) {
					vis[d] = 1;
					q.push(d);
				}
			}
		}
	}
	
	return (dis[t] != inf);
}

int dfs(int x, int now) {
	if (x == t) {
		vis[t] = 1;
		ans += now;
		return now;
	}
	
	int used = 0;
	vis[x] = 1;
	
	// Dinic 快就快在一次可以找多条 
	for (int i = cur[x]; i; i = edge[i].nxt) {
		cur[x] = i;
		int v = edge[i].v, w = edge[i].w, val = edge[i].val;
		if (dis[v] == dis[x] + val && w && !vis[v]) {
			int res = dfs(v, min(w, now - used));
			if (res) {
				used += res;
				cost += res * edge[i].val;
				edge[i].w -= res;
				edge[i ^ 1].w += res;
				if (used >= now) break;
			}
		}
	}
	
	return used;
}

void Dinic() {
	while (bfs()) {
		do {
			memset(vis, 0, sizeof(vis));
			dfs(s, inf);
		} while (vis[t]);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	cin >> n >> m >> s >> t;
	for (int i = 1, u, v, w, val; i <= m; i++) {
		cin >> u >> v >> w >> val;
		add(u, v, w, val), add(v, u, 0, -val);
	}
	
	Dinic();
	cout << ans << " " << cost << endl;
	
	return 0;
}