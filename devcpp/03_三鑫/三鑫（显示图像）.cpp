#include <bits/stdc++.h>
using namespace std;

int n, m, a[210][210], ans[210][210];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[210][210];
struct node{
	int x, y, pts;
};

int bfs(int sx, int sy) {
	if(a[sx][sy] == 1) return 0;
	memset(vis, 0, sizeof(vis));
	queue<node>q;
	vis[sx][sy] = 1;
	q.push({sx, sy, 0});
	while(!q.empty()) {
		int x = q.front().x; 
		int y = q.front().y;
		int pts = q.front().pts;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == false) {
				vis[tx][ty] = true;
				q.push({tx, ty, pts + 1});
				if(a[tx][ty] == 1) return pts + 1; 
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans[i][j] = bfs(i, j);
	for (int i = 1; i <= n; i++, puts(" "))
		for (int j = 1; j <= m; j++)
			cout << ans[i][j] << " ";
	return 0;
}
