#include <bits/stdc++.h>
#define maxn 15
using namespace std;

int n, a[maxn][maxn], f[maxn][maxn][maxn][maxn];
int my_max(int x, int s, int w, int l) {
    return max(x, max(s, max(w, l)));
}

signed main() {
    cin >> n;
    int x, y, w;
    while(cin >> x >> y >> w && (x || y || w)) a[x][y] = w;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                for (int o = 1; o <= n; o++) {
                    int walk = my_max(f[i - 1][j][k - 1][o], f[i - 1][j][k][o - 1], f[i][j - 1][k - 1][o], f[i][j - 1][k][o - 1]);
                    f[i][j][k][o] += a[i][j] + a[k][o] + walk;
                    if (i == k && j == o) f[i][j][k][o] -= a[i][j];
                }
    cout << f[n][n][n][n] << endl;
    return 0;
}
