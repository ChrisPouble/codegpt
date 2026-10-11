#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m;
vector <vector<int> > c, a, dis;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

struct node { int x, y, step; };
queue <node> que;

bool check(int x, int y, int flag) {
    if (x < 1 || x > n || y < 1 || y > m) return 0;
    if (flag == 1) return (c[x][y] == 0 ? 1 : 0);
    if (flag == 2) return (dis[x][y] != -1 ? 0 : 1);
}

void Bfs() {
    while (!que.empty()) {
        auto top = que.front();
        que.pop();

        for (int i = 0; i < 8; i++) {
            int x = top.x + dx[i];
            int y = top.y + dy[i];
            int step = top.step + 1;

            if (check(x, y, 2)) {
                dis[x][y] = step;
                que.push({ x, y, step });
            }
        }
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m;
    
    // 修复：直接使用 assign 分配好大小和初始值，不需要用 tmp 慢慢 push_back
    a.assign(n + 1, vector<int>(m + 1, 0));
    c.assign(n + 1, vector<int>(m + 1, 0));
    dis.assign(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j + 1] = c[i][j + 1] = (s[j] == '.' ? 0 : 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) continue;

            bool flag = 0;
            for (int k = 0; k < 8; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (check(x, y, 1)) flag = 1;
            }

            if (!flag) a[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                que.push({ i, j, 0 });
                dis[i][j] = 0;
            }
        }
    }

    Bfs();

    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++)
            cout << (dis[i][j] & 1 ? '.' : '#');

    return 0;
}