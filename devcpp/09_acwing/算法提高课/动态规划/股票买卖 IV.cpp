#include <bits/stdc++.h>
#define maxn 100010
#define maxk 110
using namespace std;

int n, k, ans, a[maxn], f[maxn][2 * maxk];
signed main() {
    cin >> n >> k;
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= 2 * k; j++) {
            if(j & 1) f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] - a[i]);
            else f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + a[i]);
        }
    }
    for (int i = 1; i <= k; i++) ans = max(ans, f[n][2 * i]);
    cout << ans << endl;
    return 0;
}
