#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 10;
const int N = 2e5 + 10;
typedef long long ll;

ll n;
ll a[N], dp[N], out[N], t[M], ans, v[N];
int T;

int main() {
    cin >> T;
    for (int k = 1; k <= T; k++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (t[a[i]]) {
                if (t[a[i]] == i - 1) {
                    ans += a[i];
                }
                else {
                    out[i - 1] = t[a[i]] + 1;
                    v[i - 1] = a[i];
                }
            }
            t[a[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            if (out[i]) {
                dp[i] = max(dp[i], dp[out[i] - 1] + v[i]);
            }
        }

        ans += dp[n];
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) {
            t[a[i]] = 0, a[i] = 0;
            out[i] = 0, v[i] = 0;
            dp[i] = 0;
        }
        ans = 0;
    }

    return 0;
}