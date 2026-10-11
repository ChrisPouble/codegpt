#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char c[45][45];
bool vis[45][45];
struct node{
	int x, y, pts;
};

queue<node>q;
int main() {
	cin >> n >> m;
	if(n == 1 && m == 1) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	q.push({1, 1, 1});
	vis[1][1] = 1;
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int pts = q.front().pts;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && vis[tx][ty] == false && c[tx][ty] != '#') {
				vis[tx][ty] = true;
				q.push({tx, ty, pts + 1});
			}
			if(tx == n && ty == m) {
				cout << pts + 1 << endl;
				return 0;
			}
		}
	}
	return 0;
}
