#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 10;
const int mod = 998244353;

void add_mod(int &x, int y) {
    x += y;
    if (x >= mod) x -= mod;
}

int n, fac[N];
vector <int> linker[N];
int f[N][N], tmp[N], g[N][2];

void dfs(int u, int fa) {
    f[u][0] = 1;
    for (auto v : linker[u]) {
        if (v == fa) continue;

        dfs(v, u);
        memcpy(tmp, f[u], sizeof(tmp));
        memset(f[u], 0, sizeof(f[u]));

        for (int i = 0; i < n; i++) {
            add_mod(f[u][i], 1ll * tmp[i] * g[v][0] % mod);
            if (i) add_mod(f[u][i], 1ll * tmp[i - 1] * g[v][1] % mod);
        }
    }

    for (int i = 0; i < n; i++) {
        add_mod(g[u][0], 1ll * f[u][i] * fac[i] % mod);
        add_mod(g[u][1], 1ll * f[u][i] * fac[i + 1] % mod);
    }
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }

    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = 1ll * fac[i - 1] * i % mod;

    dfs(1, 0);
    cout << g[1][0] << endl;
	return 0;
}