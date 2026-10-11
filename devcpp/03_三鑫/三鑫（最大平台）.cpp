#include <bits/stdc++.h>
using namespace std;

int n, a[110][110], sum[5000000], color;
bool vis[110][110], v[5000000];
void dfs(int x, int y, int find) {
	if(x < 1 || x > n || y < 1 || y > n || vis[x][y] || a[x][y] != find) return;
	color++;
	vis[x][y] = true;
	dfs(x + 1, y, find);
	dfs(x, y + 1, find);
	dfs(x - 1, y, find);
	dfs(x, y - 1, find);
}

int max_pingtai(int x) {
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(a[i][j] == x && vis[i][j] == false) {
				color = 0;
				dfs(i, j, x);
				ans = max(ans, color);
			}
	sum[x] = ans;
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	int ansi = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(v[a[i][j]] == 0) {
				ansi = sum[ansi] > max_pingtai(a[i][j]) ? ansi : a[i][j];
				v[a[i][j]] = 1;
			}
	cout << sum[ansi] << endl;
	cout << ansi << endl;
	return 0;
}
/*
3
7 6 7
7 7 6
7 6 6
*/ 
