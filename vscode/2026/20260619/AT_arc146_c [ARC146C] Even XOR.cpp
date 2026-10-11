#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3e5 + 10;
const int mod = 998244353;

ll n, f[N], pw[N], inv[N];

ll ksm(ll a, int b) {
    ll res = 1ll;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod, b >>= 1;
    }
    return res;
}

int main() {
    cin >> n;

    pw[0] = inv[1] = 1ll;
    for (int i = 1; i <= n + 1; i++)
        pw[i] = (pw[i - 1] * 2ll) % mod;
    
    for (int i = n + 1; i >= 2; i--)
        inv[i] = ksm(i, mod - 2);
    
    f[0] = 1, f[1] = pw[n];
    
    ll ans = 0;
    
    for (int i = 1; i <= n; i++) {
        ll choices = (pw[n] - pw[i - 1] + mod) % mod;
        f[i + 1] = f[i] * choices % mod * inv[i + 1] % mod;
    }

    for (int i = 0; i <= n + 1; i++)
        ans = (ans + f[i]) % mod;
    
    cout << ans << "\n";
    
    return 0;
}