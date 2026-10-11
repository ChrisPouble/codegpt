#include <bits/stdc++.h>
using namespace std;

int n, m, t, sx, sy, fx, fy, ans, a[10][10];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool vis[10][10];
void dfs(int x, int y) {
    if(x == fx && y == fy) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i], ty = y + dy[i];
        if(tx < 1 || tx > n || ty < 1 || ty > m || a[tx][ty] == 1 || vis[tx][ty]) continue;
        vis[tx][ty] = true;
        dfs(tx, ty);
        vis[tx][ty] = false;
    }
}

int main() {
    freopen("brick.in", "r", stdin);
    freopen("brick.out", "w", stdout);
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    vis[sx][sy] = true;
    for (int i = 1; i <= t; i++) {
        int x, y; cin >> x >> y;
        a[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}