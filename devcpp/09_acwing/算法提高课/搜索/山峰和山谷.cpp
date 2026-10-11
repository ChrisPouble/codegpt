#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, peak, valley, a[maxn][maxn];
int dx[9] = {0, 0, 1, 0, -1, 1, 1, -1, -1};
int dy[9] = {0, 1, 0, -1, 0, 1, -1, 1, -1};
bool vis[maxn][maxn];
struct node {
	int x, y;
};

void bfs(int sx, int sy, int &has_highter, int &has_lower) {
	queue<node>q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 1; i <= 8; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
			if(a[tx][ty] != a[x][y]) {
				if (a[tx][ty] > a[x][y]) has_highter = 1;
				else has_lower = 1;
			} else if(!vis[tx][ty]) vis[tx][ty] = 1, q.push({tx, ty});
		}
	}
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!vis[i][j]) {
				int sx = i, sy = j, is_highter = 0, is_lower = 0;
				bfs(sx, sy, is_highter, is_lower);
				if(!is_highter) peak++;
				if(!is_lower) valley++;
			}
	cout << peak << " " << valley << endl;
	return 0;
}
