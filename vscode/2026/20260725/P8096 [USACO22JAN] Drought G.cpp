#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 110;
const int M = 1e3 + 10;
const int mod = 1e9 + 7;

int n, H[N];
ll f[N][M], s[N][M];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;

    int minn = M;
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
        minn = min(minn, H[i]);
    }
    
    ll ans = 0;
    for (int j = 0; j <= minn; j++) {
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        for (int k = j; k <= H[1]; k++) {
            f[1][k] = 1;
            s[1][k] = k - j + 1;
        }
        
        for (int i = 2; i <= n; i++) {
            if (j > H[i - 1]) continue;
            for (int k = j; k <= H[i]; k++) {
				// f[i][k] = (f[i][k] + f[i - 1][j + p]) % mod;
                f[i][k] = ((s[i - 1][j + min(H[i - 1] - j, H[i] - k)] - (!j ? 0 : s[i - 1][j - 1])) % mod + mod) % mod;
                s[i][k] = (f[i][k] + (!k ? 0 : s[i][k - 1])) % mod;
            }
        }

        if (j > 0 && !(n & 1)) break;
        ans = (ans + f[n][j]) % mod;
    }

    cout << ans << endl;

	return 0;
}