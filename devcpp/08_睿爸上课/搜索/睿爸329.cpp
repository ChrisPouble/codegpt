#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e2 + 10;
struct node {
	int x, y, last, pts;
};
int m, n, t, sx, sy;
char mp[210][210];
bool vis[210][210][20];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<node> q;
void bfs() {
	vis[sx][sy][t] = 1;
	q.push({sx, sy, t, 0});
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int last = q.front().last;
		int pts = q.front().pts;
		q.pop();
		if(mp[x][y] == '+') {
			cout << pts << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i], tlast = last;
			if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
			if(mp[tx][ty] == '#' && tlast < 1) continue;
			if(vis[tx][ty][tlast]) continue;
			if(mp[tx][ty] == '#') tlast--;
			vis[tx][ty][tlast] = 1;
			q.push({tx, ty, tlast, pts + 1});
		}
	}
	cout << -1 << endl;
}

signed main() {
    cin >> n >> m >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == '@') sx = i, sy = j;	
		}
	bfs();
    return 0;
}
