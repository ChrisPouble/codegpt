#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e3 + 10;
const int M = 2e5 + 10; 
const int inf = 0x3f3f3f3f3f3f3f3f;

int min(int x, int y) {
	return x < y ? x : y;
}

int n, k, s, s_, t;
int top = 1;

int head[N], cur[N];

int siz;
vector<int> vec;

int find(int x) {
	int l = 0, r = vec.size() - 1;

	while (l <= r) {
		int mid = (l + r) >> 1;

		if (vec[mid] > x) l = mid + 1;
		if (vec[mid] < x) r = mid - 1;
		if (vec[mid] == x) return mid + 1;
	}
}

struct Seg {
	int l, r, len;
} seg[N];

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
	for (int i = 1; i <= t; i++) {
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
	
	vis[x] = 1;
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
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> seg[i].l >> seg[i].r;
		vec.push_back(seg[i].l);
		vec.push_back(seg[i].l);
		seg[i].len = seg[i].r - seg[i].l;
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	siz = vec.size();

	s = siz + siz + 3, s_ = s + 1, t = s_ + 1;
	// for (int i = 1; i <= n; i++) {
	// 	seg[i].l = find(seg[i].l);
	// 	seg[i].r = find(seg[i].r) + siz;
	// }

	add(s, s_, k, 0), add(s_, s, 0, 0);

	for (int i = 1; i <= n; i++) {
		int l = find(seg[i].l), r = find(seg[i].r) + siz, len = seg[i].len;
		add(s_, l, 1, 0), add(l, s_, 0, 0);
		add(l, r, 1, -len), add(r, l, 0, len);
		add(r, t, 1, 0), add(t, r, 0, 0);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int l1 = find(seg[i].l), r1 = find(seg[i].l) + siz, len1 = seg[i].len;
			int l2 = find(seg[j].l), r2 = find(seg[j].r) + siz, len2 = seg[j].len;
			if (seg[i].r <= seg[j].l) {
				add(r1, l2, 1, 0);
				add(l2, r1, 0, 0);
			}
		}
	}

	Dinic();
	cout << -cost << endl;
	
	return 0;
}

/*
4 2
1 7
6 8
7 10
9 13
*/