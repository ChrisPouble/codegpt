#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, pre;
};

int n, m, a[125][125];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool vis[125][125];
queue<node>q;
int bfs(int x, int y) {
    q.push({x, y, 0});
    vis[x][y] = 1;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int pre = q.front().pre;
        q.pop();
        if(x == n && y == m) return pre;
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if(tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] || a[tx][ty]) continue;
            q.push({tx, ty, pre + 1});
            vis[tx][ty] = 1;
        }
    }
}

signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	cout << bfs(1, 1) << endl;
    return 0;
}
