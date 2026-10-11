#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, ans = 1e9, dis[N][N];
int f[1 << N][N];
signed main() {
    memset(f, 0x3f, sizeof(f));
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dis[i][j];
    f[1][0] = 0;
    int mst = 1 << n;
    for (int i = 0; i < mst; i++) {
        if (i & 1 == 0) continue;
        for (int j = 1; j < n; j++) {
            if (i & (1 << j)) continue;
            for (int k = 0; k < n; k++) {
                if (!(i & (1 << k))) continue;
                int nst = i + (1 << j);
                f[nst][j] = min(f[i][k] + dis[k][j], f[nst][j]);
            }
        }
    }
    // for (int i = 0; i < mst; i++)
    //     for (int j = 0; j < n; j++)
    //         cout << i << " " << j << " " << f[i][j] << endl;
    for (int i = 1; i < n; i++) ans = min(ans, f[mst - 1][i] + dis[i][0]);
    cout << ans << endl;
    return 0;
}