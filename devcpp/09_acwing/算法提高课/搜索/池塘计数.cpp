#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m, ans;
bool vis[maxn][maxn];
char c[maxn][maxn];
struct node {
	int x, y;
};

void bfs(int sx, int sy) {
	queue<node>q;
	q.push({sx, sy});
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
				if(i >= 1 && i <= n && j >= 1 && j <= m && !vis[i][j] && c[i][j] == 'W') {
					vis[i][j] = 1;
					q.push({i, j});
				}
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!vis[i][j] && c[i][j] == 'W') bfs(i, j), ans++;
	cout << ans << endl; 
	return 0;
}
