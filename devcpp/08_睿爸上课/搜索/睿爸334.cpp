#include <bits/stdc++.h>
#define int long long //开个long long，以防万一 
using namespace std;

int n, m, l = 0, r = 1e9, ans = INT_MAX, map1[510][510], map2[510][510]; //map1表示地图，map2表示打卡点 
int dx[4] = {0, 1, 0, -1}; //方位数组 
int dy[4] = {1, 0, -1, 0};
bool vis[510][510];
struct node {
	int x, y; //记录一个坐标 
};

bool check(int d) {
	memset(vis, 0, sizeof(vis)); //更新数组 
	vis[1][1] = 1; //起点设为1 
	queue<node>q;
	q.push({1, 1}); //把起点放进去 
	while(!q.empty()) {
		int x = q.front().x; //取出队头元素 
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i]; //新的一个坐标 
			if(tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] || abs(map1[x][y] - map1[tx][ty]) > d) continue; //判断是否可以到达新的点 
			q.push({tx, ty}); //放入队列 
			vis[tx][ty] = 1; //进行记录 
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(map2[i][j] && !vis[i][j]) //如果这个点是打卡点并且还没有走到 
				return 0; //则返回0 
	return 1; //否则返回1 
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map1[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map2[i][j];
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) ans = min(mid, ans), r = mid - 1; //如果可以，记录答案，并且看看能否找到更小的 
		else l = mid + 1; //否则找更大的 
	}
	cout << ans << endl;
	return 0;
}
