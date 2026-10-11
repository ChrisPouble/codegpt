#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, ans, a[110][110]; //地图
int dx[4] = {0, 1, 0, -1}; //方位数组
int dy[4] = {1, 0, -1, 0};
struct node {
	int x, y, pts; //x、y表示走到哪个点，pts表示走了多少步
};

queue<node>q;
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			q.push({i, j, 0}); //放进队列
			while(!q.empty()) {
				int x = q.front().x; //取出对头元素
				int y = q.front().y;
				int pts = q.front().pts;
				q.pop();
				ans = max(ans, pts);
				for (int i = 0; i < 4; i++) {
					int tx = x + dx[i], ty = y + dy[i];
					if(tx >= 1 && tx <= n && ty >= 1 && ty <= m &&  a[tx][ty] > a[x][y]) { //边界条件
						q.push({tx, ty, pts + 1}); //把新的点放进队列
					}
				}
			}
		}
	cout << ans << endl;
	return 0;
}
