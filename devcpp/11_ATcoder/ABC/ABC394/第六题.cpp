#include <bits/stdc++.h>
#define maxn 200010 
using namespace std;

int n, u, v, ans, f[maxn][5][2];
vector<int> linker[maxn];
inline int max(int a,int b,int c,int d) {
	return max(max(a, b), max(c, d));
}

void dfs(int u, int fa) {
	f[u][0][0] = 1;
	for (auto v:linker[u]) {
		if(v == fa) continue;
		dfs(v, u);
		for (int i = 4; i >= 1; i--) { //倒序转移，防止需要的值被覆盖
			if (f[u][i - 1][0]) f[u][i][0] = max(f[u][i][0], f[u][i - 1][0] + 1);
			if (f[u][i - 1][1]) f[u][i][1] = max(f[u][i][1], f[u][i - 1][1] + 1);
			if ((f[u][i - 1][0] || f[u][i - 1][1]) && (f[v][3][0] || f[v][3][1]))
				f[u][i][1] = max(f[u][i][1], max(f[u][i - 1][0], f[u][i - 1][1]) + max(f[v][3][0], f[v][3][1]));
		}
	}
	ans = max(ans, f[u][1][1], f[u][4][0], f[u][4][1]);
	return;
}

signed main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		linker[u].push_back(v);
		linker[v].push_back(u);
	}
	dfs(1, 0);
	cout << (ans ? ans : -1) << endl;
	return 0;
}
