#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m;
char c[maxn][maxn];
int dis[maxn][maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct node {
	int x, y, pts;
};

void bfs() {
    memset(dis, -1, sizeof(dis)); 
    queue<node>q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (c[i][j] == '1') {
                q.push({i, j, 0});
                dis[i][j] = 0;
            }
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int pts = q.front().pts;
		q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if (dis[tx][ty] == -1) {
                dis[tx][ty] = pts + 1;
                q.push({tx, ty, pts + 1});
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i] + 1;
    bfs();
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            cout << dis[i][j] << " ";
    return 0;
}
