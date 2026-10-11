#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, color[maxn];
vector<int>linker[maxn];
bool dfs(int u, int c) {
	color[u] = c; //染色 
	for (auto v:linker[u]) {
		if(!color[v]) { if(dfs(v, 3 - c)) return 1; } //如果相邻的点无颜色，则染上不同的颜色 
		else if(color[v] == c) return 1; //如果颜色相同，说明不是二分图 
	}
	return 0;
}

void add(int u, int v) { //加入一条边 
	linker[u].push_back(v);
	linker[v].push_back(u);
}

signed main() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		add(u, v);
	}
	for (int i = 1; i <= n; i++)
		if(!color[i] && dfs(i, 1)) { //如果从这里搜过去搜到的不是二分图 
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}
