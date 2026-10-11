#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#define maxn 20
using namespace std;

int n, m, way[maxn], w[maxn][maxn], f[maxn][maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            for (int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
        }
    cout << f[n][m] << endl;
    int res = m;
    for (int i = n; i >= 1; i--) {
        for (int k = 0; k <= res; k++)
            if(f[i][res] == f[i - 1][res - k] + w[i][k]) {
                way[i] = k;
                res -= k;
                break;
            }
    }
    for (int i = 1; i <= n; i++) cout << i << " " << way[i] << endl;
    return 0;
}
