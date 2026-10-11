#include <bits/stdc++.h>
using namespace std;

int n;
char c[110][110];
bool vis[110][110];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0}; 
struct node {
	int x, y;
};

void bfs(int sx, int sy) {
	queue<node>q;
	vis[sx][sy] = 1;
	q.push({sx, sy}); //放入起点 
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= n && !vis[tx][ty] && c[x][y] == c[tx][ty]) { //要跟上一块相同才能染色 
				vis[tx][ty] = 1; //染色 
				q.push({tx, ty}); //接着染 
			}
		}
	}
}

int work() {
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(!vis[i][j]) { //如果没有记录 
				sum++; //区块+1 
				bfs(i, j); //开始染色 
			}
	return sum;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	cout << work() << " ";
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(c[i][j] == 'G') c[i][j] = 'R'; //变绿为红 
	memset(vis, 0, sizeof(vis));
	cout << work() << endl;
	return 0;
}
