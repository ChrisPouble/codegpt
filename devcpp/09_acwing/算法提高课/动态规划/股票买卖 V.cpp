#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, a[maxn], f[maxn][3];
signed main() {
    cin >> n;
    memset(f, -0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][2]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);
        f[i][2] = f[i - 1][1] + a[i];
    }
    cout << max(f[n][0], f[n][2]) << endl;
    return 0;
}
