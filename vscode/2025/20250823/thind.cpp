#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

struct node {
    int x, y;
};

int n, m, Q;
int now;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool vis[N][N];
char a[N][N];

queue<node> q;
void bfs(int sx, int sy) {
    q.push({sx, sy});
    now++, vis[sx][sy] = 1;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if (vis[tx][ty] || a[tx][ty] == '#') continue;

            q.push({tx, ty});
            vis[tx][ty] = 1, now++;
        }
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m >> Q;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j - 1];
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i][1] && a[i][1] == '.') bfs(i, 1);
        if (!vis[i][m] && a[i][m] == '.') bfs(i, m);
    }

    for (int i = 1; i <= m; i++) {
        if (!vis[1][i] && a[1][i] == '.') bfs(1, i);
        if (!vis[n][i] && a[n][i] == '.') bfs(n, i);
    }

    // cout << now << endl;

    int x, y;
    while (Q--) {
        cin >> x >> y;
        
        if (a[x][y] == '.') {
            cout << now << "\n";
            continue;
        }
        
        a[x][y] = '.';

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 1 || tx > n || ty < 1 || ty > m) {
            	bfs(x, y);
            	break;
            }
            if (!vis[tx][ty] || a[tx][ty] == '#') continue;
            bfs(x, y);
            break;
        }
        
        cout << now << "\n";
    }

    system("pause");
    return 0;
}