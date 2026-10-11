#include <bits/stdc++.h>
using namespace std;

int n, m, p, sx, sy, ex, ey;
char c[10][10]; //地图 
bool vis[10][10]; //进行记录一个点是否走过 
int dx[4] = {0, 1, 0, -1}; //方位数组 
int dy[4] = {1, 0, -1, 0};
struct node {
	int x, y, pts; //x、y表示走到哪个点，pts表示走了多少步 
};

queue<node>q;
int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if(c[i][j] == 'S') sx = i, sy = j; //找起点 
			if(c[i][j] == 'D') ex = i, ey = j; //找终点
		}
	vis[sx][sy] = 1; //进行记录 
	q.push({sx, sy, 0}); //放进队列 
	while(!q.empty()) {
		int x = q.front().x; //取出对头元素 
		int y = q.front().y;
		int pts = q.front().pts;
		q.pop();
		if(x == ex && y == ey) { //找到终点了 
			cout << "YES" << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == 0 && pts + 1 <= p && c[tx][ty] != 'X') { //边界条件 
				vis[tx][ty] = 1; //进行记录 
				q.push({tx, ty, pts + 1}); //把新的点放进队列 
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
