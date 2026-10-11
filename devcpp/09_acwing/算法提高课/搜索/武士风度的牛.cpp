#include <bits/stdc++.h>
#define maxn 200
using namespace std;

int n, m, sx, sy, ex, ey;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
char a[maxn][maxn];
bool vis[maxn][maxn];
struct node {
    int x, y, pts;
};

void bfs() {
    queue<node>q;
    q.push({sx, sy, 0});
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int pts = q.front().pts;
        q.pop();
        if (x == ex && y == ey) {
            cout << pts << endl;
            exit(0);
        }
        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m || vis[tx][ty] || a[tx][ty] == '*') continue;
            q.push({tx, ty, pts + 1});
            vis[tx][ty] = 1;
        }
    }
}

signed main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1];
            if (a[i][j] == 'K') sx = i, sy = j;
            if (a[i][j] == 'H') ex = i, ey = j;
        }
    }
    bfs();
	return 0;
}
