#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int n, m;
int sx, sy, ex, ey;
char a[N][N];

// 上(U, 0)，:下(D, 1)，:左(L, 2)，:右(R, 3)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char dir_char[4] = { 'U', 'D', 'L', 'R' };

bool vis[N][N][5];
int pre[N][N][5]; 

struct state {
    int x, y;
    int dir;
};

void solve() {
    queue <state> q;
    
    q.push({ sx, sy, 4 });
    vis[sx][sy][4] = 1;

    int lst = -1;

    while (!q.empty()) {
        auto [x, y, to] = q.front();
        q.pop();

        if (x == ex && y == ey) {
            lst = to;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            if (a[x][y] == 'o' && to != 4 && i != to) continue;
            if (a[x][y] == 'x' && to != 4 && i == to) continue;

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#') continue;

            if (!vis[nx][ny][i]) {
                vis[nx][ny][i] = 1;
                pre[nx][ny][i] = to;
                q.push({ nx, ny, i });
            }
        }
    }

    if (lst == -1) cout << "No\n";
    else {
        cout << "Yes\n";
        string path = "";
        int cx = ex, cy = ey, cto = lst;
        
        while (cx != sx || cy != sy) {
            path += dir_char[cto];
            int px = cx - dx[cto];
            int py = cy - dy[cto];
            int pto = pre[cx][cy][cto];
            
            cx = px;
            cy = py;
            cto = pto;
        }
        
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') { sx = i; sy = j; }
            if (a[i][j] == 'G') { ex = i; ey = j; }
        }
    }

    solve();

    // system("pause");
    return 0;
}