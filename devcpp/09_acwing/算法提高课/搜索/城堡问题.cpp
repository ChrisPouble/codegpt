#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m, ans1, ans2;
//南、东、北、西 
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
bool vis[maxn][maxn];
int a[maxn][maxn];
struct node {
	int x, y;
};

void bfs(int sx, int sy) {
	queue<node>q;
	q.push({sx, sy}), vis[sx][sy] = 1;
	int res = 0;
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		res++;
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty]) continue;
			int k = a[tx][ty], v[5];
			memset(v, 0, sizeof(v));
			for (int j = 3; j >= 0; j--)
				if (k >= (1 << j)) v[j + 1] = 1, k -= (1 << j);
			if(i == 1 && !v[2]) {
				vis[tx][ty] = 1;
				q.push({tx, ty});
			}
			if(i == 2 && !v[1]) {
				vis[tx][ty] = 1;
				q.push({tx, ty});
//				cout << tx << " " << ty << " " << "Fafsda" << endl;
			}
			if(i == 3 && !v[4]) {
				vis[tx][ty] = 1;
				q.push({tx, ty});
			}
			if(i == 4 && !v[3]) {
				vis[tx][ty] = 1;
				q.push({tx, ty});
//				cout << "fafda" << endl;
			}
		}
	}
	ans2 = max(ans2, res);
//	cout << res << endl;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j]) bfs(i, j), ans1++;
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}
