#include <bits/stdc++.h>
using namespace std;
struct node {
    int x, y, step;
};
int f[301][301][2], n, m, cnt, ans = -0x7fffffff;
char mp[301][301];
int dx[] = { 2, -2, 0, 0 }, dy[] = { 0, 0, 2, -2 };

void bfs(int fx, int fy, int v) {
    queue<node> q;
    f[fx][fy][v] = 1;
    q.push({ fx, fy, 1 });
    while (!q.empty()) {
        node h = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = h.x + dx[i], yy = h.y + dy[i];
            if (xx >= 1 && xx <= 2 * n + 1 && yy >= 1 && yy <= 2 * m + 1 && mp[xx][yy] == ' ' &&
                mp[h.x + dx[i] / 2][h.y + dy[i] / 2] == ' ' && !f[xx][yy][v]) {
                f[xx][yy][v] = h.step + 1;
                q.push({ xx, yy, h.step + 1 });
            }
        }
    }
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * m + 1; j++)
            if (f[i][j][v] == 0)
                f[i][j][v] = 0x7fffffff;
}
int main() {
    cin >> m >> n;
    getchar();
    memset(mp, '*', sizeof(mp));
    for (int i = 1; i <= 2 * n + 1; i++) {
        gets(mp[i] + 1);
        for (int j = 1; j <= 2 * m + 1; j++)
            if (mp[i][j] == '*')
                mp[i][j] = ' ';
    }
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2 * m + 1; j++) {
            if (mp[i][j] == '-' || mp[i][j] == '+' || mp[i][j] == '|')
                continue;
            if (i == 1) {
                bfs(i + 1, j, cnt);
            } else if (j == 1) {
                bfs(j + 1, i, cnt);
            } else if (i == 2 * n + 1) {
                bfs(i - 1, j, cnt);
            } else if (j == 2 * m + 1) {
                bfs(i, j - 1, cnt);
            } else
                cnt--;
            cnt++;
        }
    }
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * m + 1; j++)
            if (min(f[i][j][0], f[i][j][1]) != 0x7fffffff)
                ans = max(ans, min(f[i][j][0], f[i][j][1]));
    cout << ans;
    return 0;
}