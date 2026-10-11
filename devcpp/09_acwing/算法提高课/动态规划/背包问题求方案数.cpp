#include <bits/stdc++.h>
#define maxn 1010
#define mod 1000000007
using namespace std;

int n, m, ans, v[maxn], w[maxn], f[maxn][maxn], g[maxn][maxn];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    g[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if(f[i][j] == f[i - 1][j]) g[i][j] = (g[i][j] + g[i - 1][j]) % mod;
            if(j >= v[i] && f[i][j] == f[i - 1][j - v[i]] + w[i]) g[i][j] = (g[i][j] + g[i - 1][j - v[i]]) % mod;
        }
    for (int i = 0; i <= m; i++)
        if (f[n][i] == f[n][m]) ans = (ans + g[n][i]) % mod;
    cout << ans << endl;
    return 0;
}
