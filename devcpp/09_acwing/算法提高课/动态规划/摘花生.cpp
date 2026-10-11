#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int T, n, m, a[maxn][maxn], f[maxn][maxn];
void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) f[i][1] = f[i - 1][1] + a[i][1];
    for (int i = 1; i <= m; i++) f[1][i] = f[1][i - 1] + a[1][i];
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            f[i][j] = a[i][j] + max(f[i - 1][j], f[i][j - 1]);
    printf("%d\n", f[n][m]);
}

signed main() {
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}
