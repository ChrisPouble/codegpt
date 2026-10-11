#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e3 + 10;
const int M = 4e6 + 10; 
const int inf = 0x3f3f3f3f3f3f3f3f;

int min(int x, int y) {
	return x < y ? x : y;
}

int n, m, s, t;
int top = 1, cnt;

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
	for (int i = 1; i <= cnt; i++) {
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
	while (bfs()) dfs(s, inf);
	
	return ans;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	int sum = 0;
	cin >> n, s = n + 1, t = n + 2;

	for (int i = 1, x; i <= n; i++) {
		cin >> x, sum += x;
        add(s, i, x), add(i, s, 0);
	}

    for (int i = 1, x; i <= n; i++) {
		cin >> x, sum += x;
        add(i, t, x), add(t, i, 0);
	}

    cin >> m;

    cnt = t;
    for (int i = 1, k, c1, c2, x; i <= m; i++) {
        cin >> k >> c1 >> c2, sum += c1 + c2;
        add(s, ++cnt, c1), add(cnt, s, 0);
        add(++cnt, t, c2), add(t, cnt, 0);
        while (k--) {
            cin >> x;
            add(cnt - 1, x, inf), add(x, cnt - 1, 0);
            add(x, cnt, inf), add(cnt, x, 0);
        }
    }
	
	cout << sum - Dinic() << endl;
	return 0;
}
