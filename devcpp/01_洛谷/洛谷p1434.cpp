#include <bits/stdc++.h>
using namespace std;

int R, C, ans, a[110][110], jyh[110][110];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dfs(int x, int y) {
	if(jyh[x][y] != 0) return jyh[x][y];
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= R && ty >= 1 && ty <= C && a[x][y] > a[tx][ty]) {
			jyh[x][y] = max(jyh[x][y], dfs(tx, ty));
		} 
	}
	jyh[x][y]++;
	return jyh[x][y];
}

int main() {
	cin >> R >>C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			cin >> a[i][j];
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			ans = max(dfs(i, j), ans);
	cout << ans << endl;
	return 0;
} 
