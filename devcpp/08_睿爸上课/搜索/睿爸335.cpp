#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, ans;
char a[55][55]; //地图
bool vis[55][55];
int dx[4] = {0, 1, 0, -1}; //方位数组
int dy[4] = {1, 0, -1, 0};
struct node {
	int x, y; //x、y表示走到哪个点
};

void bfs(int sx, int sy) { //bfs染色 
	queue<node>q;
	q.push({sx, sy}); //放进队列
	vis[sx][sy] = 1;
	while(!q.empty()) {
		int x = q.front().x; //取出队头元素
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty] && a[x][y] <= a[tx][ty]) { //边界条件
				vis[tx][ty] = 1;
				q.push({tx, ty}); //把新的点放进队列
			}
		}
	}
}

signed main() {
	cin >> k;
	while(k--) {
		ans = 0;
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		for (char c = 'a'; c <= 'z'; c++) //枚举最高点 
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					if(!vis[i][j] && a[i][j] == c) { //如果这个点没有被染色过并且还是最高点，那么进行染色 
						bfs(i, j);
						ans++;
					}
		cout << ans << endl;
	}
	return 0;
}
