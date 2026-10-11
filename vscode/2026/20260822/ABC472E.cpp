#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m;
int dep[N], fa[N];
vector<int> g[N];

void solve() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dep[i] = -1;
        fa[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue <int> q;
    dep[1] = 0; q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dep[v] != -1) continue; 
            dep[v] = dep[u] + 1;
            fa[v] = u; 
            q.push(v);
        }
    }

    int canu = -1, canv = -1;
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (u >= v) continue;
            if ((dep[u] & 1) == (dep[v] & 1)) {
                canu = u; 
                canv = v; 
                break;
            }
        }
        if (canu != -1) break;
    }

    if (canu == -1) { 
        cout << -1 << "\n"; 
        return; 
    }

    int u = canu, v = canv;
    vector <int> path_u, path_v;

    while (u != v) {
        path_u.push_back(u);
        path_v.push_back(v);
        u = fa[u];
        v = fa[v];
    }
    path_u.push_back(u);

    vector<int> cycle = path_u;
    for (int i = (int)path_v.size() - 1; i >= 0; i--) {
        cycle.push_back(path_v[i]);
    }

    cout << cycle.size() << "\n";
    for (int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] << (i + 1 == cycle.size() ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    
    return 0;
}