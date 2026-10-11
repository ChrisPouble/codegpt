#include <bits/stdc++.h>
using namespace std;

int n, a[210], w[210][210], f[210][210], g[210][210], maxans, minans = 1e9;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof(f));
    for (int i = n; i >= 1; i--) {
        f[i][i] = 0;
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            f[i][j] += w[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k < j; k++)
				g[i][j] = max(g[i][j], g[i][k] + g[k + 1][j]);
            g[i][j] += w[i][j];
        }
    printf("%d\n%d", f[1][n], g[1][n]);
    return 0;
}
