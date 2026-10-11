#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 10;

int n, m;
ll r[N], w[N], g[N];

signed main() {    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    mt19937 rng(time(0));
    
    ll target = 0;
    for (int u = 1; u <= n; u++) {
        target += (w[u] = rng());
    }

    ll now = 0;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        r[v] += w[u];
        g[v] = r[v];
        now += w[u];
    }

    int q; cin>> q;
    for (int pro = 1; pro <= q; pro++) {
        int opt, u, v; cin >> opt;
        if (opt == 1) {
            cin >> u >> v;
            r[v] -= w[u];
            now -= w[u];
        } else if (opt == 2) {
            cin >> v;
            now -= r[v];
            r[v] = 0;
        } else if (opt == 3) {
            cin >> u >> v;
            r[v] += w[u];
            now += w[u];
        } else if (opt == 4) {
            cin >> v;
            now += g[v] - r[v];
            r[v] = g[v];
        }

        cout << (now == target ? "YES\n" : "NO\n");
    }

    return 0;
}