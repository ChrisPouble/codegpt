#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 10;

int n, m, k;
int repc[N], colc[N];
vector<vector<char> > a;
map <int, map <int, bool> > vis;

struct node { int x, y, stp; };
queue <node> que;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int ans;

void BFS() {
    while (!que.empty()) {
        auto hup = que.front(); que.pop();
        if (hup.stp > k) continue; ans ++;

        // cout << hup.x << " " << hup.y << "\n";

        for (int i = 0; i < 4; i++) {
            int px = hup.x + dx[i];
            int py = hup.y + dy[i];

            if (px < 1 || px > n || py < 1 || py > m || a[px][py] == '#') continue;
            if (vis[px][py]) continue; vis[px][py] = 1;
            que.push({ px, py, hup.stp + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        vector <char> b; b.resize(m + 1);
        for (int j = 1; j <= m; j++)
            cin >> b[j]; a[i] = b;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') repc[i] = -1;
        }
        if (repc[i] != -1) repc[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j][i] == '#') colc[i] = -1;
        }
        if (colc[i] != -1) colc[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (repc[i] == 1 && colc[j] == 1) {
                que.push({ i, j, 0 });
                vis[i][j] = 1;
                // cout << "!!!\n";
            }
        }
    }
    
    BFS(), cout << ans << endl;

    return 0;
}