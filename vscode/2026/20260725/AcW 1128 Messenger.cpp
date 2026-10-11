// Problem: AcWing - 信使
// URL: https://www.acwing.com/problem/content/description/1130/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int N = 110;
const int inf = 0x3f3f3f3f;

struct edge { int to, w; };
vector<edge> linker[N];
priority_queue<PII, vector<PII>, greater<PII> > q;

int n, m;
int dis[N];
bool vis[N];

void Dijkstra() {
    for (int i = 1; i <= n; i++) {
        dis[i] = inf, vis[i] = 0;
    }
    
    q.push({ 0, 1 }), dis[1] = 0;

    while (!q.empty()) {
        auto tp = q.top(); q.pop();
        int x = tp.second;

        if (vis[x]) continue;
        vis[x] = 1;
        
        for (auto [ v, w ] : linker[x]) {
            if (dis[v] <= dis[x] + w) continue;

            dis[v] = dis[x] + w;
            q.push({ dis[v], v });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        linker[u].push_back({ v, w });
        linker[v].push_back({ u, w });
    }

    Dijkstra();

    int res = -1;
    for (int i = 1; i <= n; i++)
        res = max(res, dis[i]);

    if (res == inf) res = -1;
    cout << res << endl;

    return 0;
}