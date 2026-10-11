#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
char c[110][110];
bool vis[110][110];
void dfs(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m || vis[x][y] || c[x][y] == '.') return;
    vis[x][y] = 1;
    dfs(x - 1, y - 1);
    dfs(x - 1, y);
    dfs(x - 1, y + 1);
    dfs(x, y - 1);
    dfs(x, y + 1);
    dfs(x + 1, y - 1);
    dfs(x + 1, y);
    dfs(x + 1, y + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if(vis[i][j] == 0 && c[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
    cout << ans << endl;
    return 0;
}