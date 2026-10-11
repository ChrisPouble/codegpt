#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 210;
const int M = 5e3 + 10; 
const int inf = 0x3f3f3f3f3f3f3f3f;

int min(int x, int y) {
	return x < y ? x : y;
}

int n, m, s, t;
int top = 1;

int head[N], cur[N];
struct node {
	int v, w;
	int nxt;
} edge[M * 2];

void add(int u, int v, int w) {
	edge[++top] = { v, w };
	edge[top].nxt = head[u];
	head[u] = top;
}

int ans, dep[N], vis[N];

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		cur[i] = head[i];
		vis[i] = 0, dep[i] = inf;
	}
	
	vis[s] = 1, dep[s] = 1, q.push(s);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		
		vis[x] = 0;
		
		// 分层 
		for (int i = head[x]; i; i = edge[i].nxt) {
			int d = edge[i].v;
			if (dep[d] > dep[x] + 1 && edge[i].w) {
				dep[d] = dep[x] + 1;
				if (!vis[d]) {
					vis[d] = 1;
					q.push(d);
				}
			}
		}
	}
	
	return (dep[t] != inf);
}

int dfs(int x, int now) {
	if (x == t) {
		ans += now;
		return now;
	}
	
	int used = 0;
	
	// Dinic 快就快在一次可以找多条 
	for (int i = cur[x]; i; i = edge[i].nxt) {
		cur[x] = i;
		int v = edge[i].v, w = edge[i].w;
		if (dep[v] == dep[x] + 1 && w) {
			int res = dfs(v, min(w, now - used));
			if (res) {
				used += res;
				edge[i].w -= res;
				edge[i ^ 1].w += res;
				if (used >= now) break;
			}
		}
	}
	
	return used;
}

int Dinic() {
	ans = 0;
	while (bfs()) {
		dfs(s, inf);
	}
	
	return ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	cin >> n >> m >> s >> t;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		add(u, v, w), add(v, u, 0);
	}
	
	cout << Dinic() << endl;
	return 0;
}