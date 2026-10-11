#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ans, vis[30][30];
char c[30][30];
int zc(int x, int y) {
    return (x == 1 || c[x - 1][y] == '.') + (x == n || c[x + 1][y] == '.')
        + (y == 1 || c[x][y - 1] == '.') + (y == m || c[x][y + 1] == '.');
}

int dfs(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m || vis[x][y] != 0 || c[x][y] == '.') return 0;
    vis[x][y] = 1;
    int sum = zc(x, y);
    sum += dfs(x - 1, y - 1);
    sum += dfs(x - 1, y);
    sum += dfs(x - 1, y + 1);
    sum += dfs(x, y - 1);
    sum += dfs(x, y + 1);
    sum += dfs(x + 1, y - 1);
    sum += dfs(x + 1, y);
    sum += dfs(x + 1, y + 1);
    return sum;
}

int main() {
    cin >> n >> m >> sx >> sy;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    ans = dfs(sx, sy);
    cout << ans << endl;
    return 0;
}