#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct edge { int to, w; };

int n, m, S, T, dis[N];
bool vis[N];

priority_queue <pair<int, int> > que;
vector <edge> linker[N];

void add(int x, int y, int w) {
    linker[x].push_back({ y, w });
}

void dijkstra(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0, que.push({ 0, st });

    while (!que.empty()) {
        int x = que.top().second; que.pop();

        if (vis[x]) continue;
        vis[x] = 1;

        for (auto k : linker[x]) {
            int v = k.to, w = k.w;
            if (dis[v] > dis[x] + w) {
                dis[v] = dis[x] + w;
                que.push({ -dis[v], v });
            }
        }
    }
}

signed main() {
    cin >> n >> m >> S >> T;
    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y, add(x, y, 1);
    }

    for (int i = 1; i <= n; i++) {
        sort(linker[i].begin(), linker[i].end(), [](edge u, edge v) {
            return u.to < v.to;
        });

        if (!linker[i].empty()) linker[i][0].w = 0;
    }
    
    dijkstra(S);
    cout << (dis[T] == inf ? -1 : dis[T]) << endl;

    return 0;
}