#include <bits/stdc++.h>
using namespace std;

int n, m, a[110][110];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[110][110];
struct node{
	int x, y, fx, turn; //fx代表方向，0代表右，1代表下，2代表左，3代表上 
};
queue<node>q;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	for(int i = 0; i < 4; i++) {
		int tx = sx + dx[i], ty = sy + dy[i];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == false && a[tx][ty] == 0) {
			q.push({tx, ty, i, 0});
			vis[tx][ty] = true;
		}
	}
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int fx = q.front().fx;
		int turn = q.front().turn;
		q.pop();
		if(x + dx[fx] >= 1 && x + dx[fx] <= n && y + dy[fx] >= 1 && y + dy[fx] <= m && vis[x + dx[fx]][y + dy[fx]] == false && a[x + dx[fx]][y + dy[fx]] == 0) {
			q.push({x + dx[fx], y + dy[fx], fx, turn});
			vis[x + dx[fx]][y + dy[fx]] = true;
			if(x + dx[fx] == ex && y + dy[fx] == ey) {
				cout << turn << endl;
				return 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			if(i == fx) continue;
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == false && a[tx][ty] == 0) {
				q.push({tx, ty, i, turn + 1});
				vis[tx][ty] = true;
				if(tx == ex && ty == ey) {
					cout << turn + 1 << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
