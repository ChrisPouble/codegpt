#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll mul_mod(ll a, ll b, ll mod) {
    a %= mod, b %= mod;
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    ll pmd = 1;
    __int128 M = 1;
    
    for (int d = 1; ; ++d) {
        pmd = mul_mod(pmd, 10, m);
        if (M > n) break;
        
        ll cnty = min(9LL * (ll)M, n - (ll)M + 1);
        
        ll A = (pmd - 1 + m) % m;
        ll g = gcd(m, A);
        ll k = m / g;
        ll cntx = n / k;

        ans = (ans + ( (cntx % MOD) * (cnty % MOD) ) % MOD) % MOD;
        
        M *= 10;
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while (T--) solve();
    return 0;
}