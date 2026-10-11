#include <bits/stdc++.h>
using namespace std;

int W, H, color;
char c[25][25];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[25][25];
void dfs(int x, int y) {
	color++;
	for (int i = 0; i <= 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= H && ty >= 1 && ty <= W && c[tx][ty] != '#' && vis[tx][ty] == false) {
			vis[tx][ty] = true;
			dfs(tx, ty);
		}
	}
}

int main() {
	while(1) {
		cin >> W >> H;
		if(W == 0 && H == 0) return 0;
		color = 0;
		memset(vis, 0, sizeof(vis));
		int sx, sy;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++) {
				cin >> c[i][j];
				if(c[i][j] == '@') sx = i, sy = j;
			}
		vis[sx][sy] = true;
		dfs(sx, sy);
		cout << color << endl;
	}
	return 0;
}
