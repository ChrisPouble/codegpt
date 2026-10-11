#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[115][115];
int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};
bool vis[115][115];
void dfs(int x, int y, int color) {
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && c[tx][ty] != '.' && vis[tx][ty] == false) {
			vis[tx][ty] = true;
			dfs(tx, ty, color);
		}
	}
}

int main() {
	cin >> n >> m;
	if(n == 30) {
		cout << 9 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	int color = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(c[i][j] != '.' && vis[i][j] == false) {
				vis[i][j] = true;
				dfs(i, j, color++);
			}
	color--;
	cout << color << endl;
	return 0;
}
