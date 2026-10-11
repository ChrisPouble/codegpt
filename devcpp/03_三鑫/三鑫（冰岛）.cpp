#include <bits/stdc++.h>
using namespace std;

int n, a[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[1010][1010]; //一定要把数组开到1000*1000那么大，否则会运行时错误 
struct node{
	int x, y, pts;
};
queue<node>q;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	if(sx == ex && sy == ey) { //如果起点和终点在一起，就输出0 
		cout << 0 << endl;
		return 0;
	}
	if(a[sx][sy] == 1 || a[ex][ey] == 1) { //如果起点或终点是墙，就输出"impossible"
		cout << "impossible" << endl;
		return 0;
	}
	if(a[ex + 1][ey] == 0 && a[ex - 1][ey] == 0 && a[ex][ey - 1] == 0 && a[ex][ey + 1] == 0) { //如果终点四周没有障碍物，就说明无法到达，输出"impossible"
		cout << "impossible" << endl;
		return 0;
	}
	q.push({sx, sy, 0});
	vis[sx][sy] = true;
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int pts = q.front().pts;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x, ty = y; //这里直接赋值，因为后面会进行走动 
			while(true) { //进入死循环，不到判断完不结束 
				int nx = tx + dx[i];
				int ny = ty + dy[i];
				if(nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == 0) tx = nx, ty = ny; //注意：这里没有!vis[nx][ny]，会在第50行判断 
				else break;
			}
			if(tx == ex && ty == ey) {
				cout << pts + 1 << endl;
				return 0;
			}
			if(!vis[tx][ty]) { //如果被访问过，就不输出 
				//cout << tx << " " << ty << " " << pts + 1 << "\n";
				q.push({tx, ty, pts + 1});
				vis[tx][ty] = 1;
			}
		}
	}
	cout << "impossible" << endl; //能出来就说明走不到终点 
	return 0;
}
