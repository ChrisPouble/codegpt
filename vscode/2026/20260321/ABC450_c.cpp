#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int n, m, ans;
bool vis[N][N];
char c[N][N];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct node {
	int x, y;
};

void bfs(int sx, int sy) {
	queue<node> q;
	q.push({ sx, sy });
    vis[sx][sy] = 1;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
        for (int p = 0; p < 4; p++) {
            int i = dx[p] + x, j = dy[p] + y;
            if (i >= 2 && i < n && j >= 2 && j < m && !vis[i][j] && c[i][j] == '#') {
				vis[i][j] = 1;
				q.push({i, j});
            }
        }
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> c[i][j];
    
	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++)
			if (!vis[i][j] && c[i][j] == '#')
                bfs(i, j), ans++;
    
	cout << ans << endl; 
	return 0;
}