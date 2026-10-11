#include <bits/stdc++.h>
using namespace std;

int n, a[110][110];
bool vis[110][110];
bool dfs1(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > n || vis[x][y] == true || a[x][y] != 1) return false;
	if(x == 1) return true;
	vis[x][y] = true;
	return dfs1(x, y + 1) || dfs1(x, y - 1) || dfs1(x + 1, y) || dfs1(x + 1, y - 1) || dfs1(x - 1, y) || dfs1(x - 1, y + 1);
}

bool dfs2(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > n || vis[x][y] == true || a[x][y] != -1) return false;
	if(y == 1) return true;
	vis[x][y] = true;
	return dfs2(x, y + 1) || dfs2(x, y - 1) || dfs2(x + 1, y) || dfs2(x + 1, y - 1) || dfs2(x - 1, y) || dfs2(x - 1, y + 1);
}

int main() {
	int T; cin >> T;
	while(T--) {
		bool is = false;
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i++)
			if(dfs1(n, i)) {
				cout << "Jimmy" << "\n";
				is = true;
				break;
			}
		if(is == true) continue;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
			if(dfs2(i, n)) {
				cout << "Chen" << "\n";
				is = true;
				break;
			}
		if(is == true) continue;
		cout << "yet" << "\n";
	}
	return 0;
}
/*
1
4
0 1 -1 -1
0 -1 1 1
-1 -1 1 0
0 0 1 0
*/
