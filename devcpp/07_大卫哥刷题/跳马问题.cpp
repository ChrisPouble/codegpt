#include <bits/stdc++.h>
using namespace std;

int n, ans, a[10][10], vis[10][10];
void dfs(int pts, int x, int y) {
	if(x < 1 || x > 5 || y < 1 || y > 5 || vis[x][y] != 0) return;
	vis[x][y] = pts;
	cout << vis[x][y] << endl;
	if(pts == 25) {
//		if(ans <= 5) {
//			for (int i = 1; i <= 5; i++, puts(" "))
//				for (int j = 1; j <= 5; j++)
//					cout << a[i][j] << " ";
//			ans++;
//		} else exit(0);
		return;
	}
	dfs(pts + 1, x + 2, y + 1);
	dfs(pts + 1, x + 1, y + 2);
	dfs(pts + 1, x - 1, y - 2);
	dfs(pts + 1, x - 1, y + 2);
	dfs(pts + 1, x + 2, y - 1);
	dfs(pts + 1, x + 1, y - 2);
	dfs(pts + 1, x - 2, y + 1);
	dfs(pts + 1, x - 2, y - 1);
	vis[x][y] = 0;
}

int main() {
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			cin >> a[i][j];
	dfs(1, 1, 1);
	return 0;
}
