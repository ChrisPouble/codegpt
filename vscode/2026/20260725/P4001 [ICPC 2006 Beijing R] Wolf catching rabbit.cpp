#include <bits/stdc++.h>
using namespace std;

#define xx first
#define yy second

const int N = 1e3 + 10;

struct Edge { int tox, toy, w; };
vector <Edge> linker[N][N * 2];
/*
    左下三角形（靠近左下角）：(i, 2j - 1)
    右上三角形（靠近右上角）：(i, 2j)

    (i, j) ------------ (i, j+1)
     |  \     右上      |
     |    \   三角形     |
     |      \  (i, 2j)  |
     |  左下  \         |
     | 三角形   \       |
     | (i, 2j-1) \      |
    (i+1, j) ---------- (i+1, j+1)
*/

struct Node {
    int x, y, w;
    bool operator<(const Node& b) const {
        return b.w < w;
    }
};

int n, m, dis[N][N];
bool vis[N][N];

void AddEdge(int xx1, int yy1, int xx2, int yy2, int w) {
    linker[xx1][yy1].push_back({ xx2, yy2, w });
}

void Dijkstra(int stx, int sty) {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Node> q;

    dis[stx][sty] = 0;
    q.push({ stx, sty, 0 });

    while (!q.empty()) {
        Node now = q.top(); q.pop();

        int x = now.x, y = now.y;
        if (vis[x][y]) continue;
        vis[x][y] = 1;

        for (auto i : linker[x][y]) {
            int tox = i.tox, toy = i.toy, w = i.w;
            if (dis[x][y] + w < dis[tox][toy]) {
                dis[tox][toy] = dis[x][y] + w;
                if (!vis[tox][toy]) q.push({ tox, toy, dis[tox][toy] });
            }
        }
    }
}

int main() {
    cin >> n >> m;

    if (n == 1 || m == 1) {
        int ans = (1 << 30);
        for (int i = 1; i < max(n, m); i++) {
            int w; cin >> w;
            ans = min(ans, w);
        }
        cout << ans << endl; return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int w; cin >> w;
            if (i == 1) {
                AddEdge(i, j << 1, n + 1, m + 1, w);
                AddEdge(n + 1, m + 1, i, j << 1, w);
            } else if (i == n) {
                AddEdge(i - 1, (j << 1) - 1, n, m, w);
                AddEdge(n, m, i - 1, (j << 1) - 1, w);
            } else {
                AddEdge(i - 1, (j << 1) - 1, i, j << 1, w);
                AddEdge(i, j << 1, i - 1, (j << 1) - 1, w);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int w; cin >> w;
            if (j == 1) {
                AddEdge(n, m, i, (j << 1) - 1, w);
                AddEdge(i, (j << 1) - 1, n, m, w);
            } else if (j == m) {
                AddEdge(n + 1, m + 1, i, (m - 1) << 1, w);
                AddEdge(i, (m - 1) << 1, n + 1, m + 1, w);
            } else {
                AddEdge(i, (j - 1) << 1, i, (j - 1) << 1 | 1, w);
                AddEdge(i, (j - 1) << 1 | 1, i, (j - 1) << 1, w);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int w; cin >> w;
            AddEdge(i, (j << 1) - 1, i, j << 1, w);
            AddEdge(i, j << 1, i, (j << 1) - 1, w);
        }
    }

    Dijkstra(n, m);
    cout << dis[n + 1][m + 1] << endl;

    return 0;
}