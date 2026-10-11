#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1005;
const int M = 10005; 
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

void add_edge(int u, int v, int w) {
    add(u, v, w);
    add(v, u, 0);
}

int ans, cnt, dep[N], vis[N];

bool bfs() {
	queue<int> q;
	for (int i = 1; i <= t; i++) {
		cur[i] = head[i];
		vis[i] = 0, dep[i] = inf;
	}
	
	vis[s] = 1, dep[s] = 1, q.push(s);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		vis[x] = 0;
		
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
	vis[x] = 1;
	
	for (int i = cur[x]; i; i = edge[i].nxt) {
		cur[x] = i;
		int v = edge[i].v, w = edge[i].w;
		if (dep[v] == dep[x] + 1 && w && !vis[v]) {
			int res = dfs(v, min(w, now - used));
			if (res) {
				used += res;
				edge[i].w -= res;
				edge[i ^ 1].w += res;
				if (used >= now) break;
			}
		}
	}
	
	vis[x] = 0;
	return used;
}

int Dinic() {
	while (bfs()) dfs(s, inf);
	return ans;
}

char grid[35][35];
int id[35][35];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	int H, W; 
    if (!(cin >> H >> W)) return 0;
	
	for (int i = 1; i <= H; i++) {
		string str; cin >> str;
		for (int j = 1; j <= W; j++)
			grid[i][j] = str[j - 1];
	}
	
	vector <int> weight; 
	weight.push_back(0); 
	
	for (int i = 1; i <= H; i++) {
	    int j = 1;
	    while (j <= W) {
	        if (grid[i][j] != '#') {
	            cnt++; 
                int w = 0;
	            // 【修复 1】避免死循环，应为 j <= W
	            while (j <= W && grid[i][j] != '#') {
	                if (grid[i][j] == '+') w++;
	                else if (grid[i][j] == '-') w--;
	                id[i][j] = cnt; 
                    j++;
	            }
	            weight.push_back(w);
	        } else {
	            j++;
	        }
	    }
	}
	
    // 【修复 2】不能 ++cnt 破坏连通块计数器
	s = cnt + 1; 
    t = cnt + 2;
	
	int sum_positive = 0;
	for (int i = 1; i <= cnt; i++) {
	    if (weight[i] > 0) {
	        sum_positive += weight[i];
	        add_edge(s, i, weight[i]); 
	    } else if (weight[i] < 0) {
	        add_edge(i, t, -weight[i]);
	    }
	}
	
	set<pair<int, int>> deps; 
	for (int i = 1; i < H; i++) {
	    for (int j = 1; j <= W; j++) {
	        if (grid[i][j] != '#' && grid[i + 1][j] != '#') {
	            int u = id[i][j];
	            int v = id[i + 1][j];
	            if (u != v && !deps.count({v, u})) {
	                deps.insert({v, u});
	                add_edge(v, u, inf); 
	            }
	        }
	    }
	}
	
	int min_cut = Dinic();
	cout << sum_positive - min_cut << "\n";
	
	return 0;
}