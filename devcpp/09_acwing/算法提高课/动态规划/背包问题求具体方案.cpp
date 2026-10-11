#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m, v[maxn], w[maxn], f[maxn][maxn];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i + 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
        }
    int k = m;
    for (int i = 1; i <= n; i++)
        if(k >= v[i] && f[i][k] == f[i + 1][k - v[i]] + w[i]) {
            cout << i << " ";
            k -= v[i];
        }
    return 0;
}
