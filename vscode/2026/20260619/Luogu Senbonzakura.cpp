#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;

int n, q, a[N];
int fac[N];
int sum[N][35];

void solve() {
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 32; j++) {
            sum[i][j] = sum[i - 1][j];
            sum[i][j] += ((fac[j] & a[i]) >= 1ll);
        }
    }

    for (int tim = 1, op, k, l, r; tim <= q; tim++) {
        cin >> op >> k >> l >> r;

        int ans = 0ll;
        for (int j = 0; j <= 32; j++) {
            int get = sum[r][j] - sum[l - 1][j];
            if (op == 0 && (k & (1 << j)))
                ans += (get & 1ll) * fac[j];
            if (op == 1)
                ans += (max(get, ((k & fac[j]) >= 1ll) * (r - l + 1)) & 1ll) * fac[j];
        }

        cout << ans << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fac[0] = 1ll;
    for (int i = 1; i <= 32; i++)
        fac[i] = fac[i - 1] * 2ll;

    int T = 1;
    while (T--) solve();
    return 0;
}