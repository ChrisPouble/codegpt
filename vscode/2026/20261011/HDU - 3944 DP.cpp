// Problem: HDU - 3944 DP?
// URL: https://vjudge.net/problem/HDU-3944
// Memory Limit: 125 MB 
// Time Limit: 3000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;

ll ans[N], fac[N], inv[N];

ll ksm(ll base, ll cap, ll mod) {
    ll res = 1; base %= mod;
    
    while (cap) {
        if (cap & 1) res = res * base % mod;
        base = base * base % mod;
        cap >>= 1;
    }
    
    return res;
}

ll C(ll n, ll k, ll p) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % p * inv[n - k] % p;
}

ll lucas(ll n, ll k, ll p) {
    if (k < 0 || k > n) return 0;
    if (n < p && k < p) return C(n, k, p);
    return C(n % p, k % p, p) * lucas(n / p, k / p, p) % p;
}

void init(int mod) {
	inv[0] = fac[0] = 1;
    for (ll i = 1; i < mod; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }

    inv[mod - 1] = ksm(fac[mod - 1], mod - 2, mod);
    for (ll x = mod - 2; x >= 1ll; x--) {
    	inv[x] = inv[x + 1] * (x + 1) % mod;
    }
}

struct type { int id; ll n, k, p; } Type[N * 10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k, p; int tot = 0;
    while (cin >> n >> k >> p) {
    	++tot, Type[tot] = { tot, n, k, p };
    }
	
	sort(Type + 1, Type + tot + 1, [](type x, type y){ return x.p < y.p; });
	
    for (int i = 1; i <= tot; i++) {
    	auto now = Type[i];
    	if (i == 1 || now.p != Type[i - 1].p)
    		init(now.p);
    	
    	ll a = now.n - now.k;
		if (a >= now.k) {
			ans[now.id] = (a % now.p + lucas(now.n + 1, now.k, now.p)) % now.p;
		} else {
			ans[now.id] = (now.k % now.p + lucas(now.n + 1, a, now.p)) % now.p;
		}
    }
    
    for (int i = 1; i <= tot; i++) {
    	cout << "Case #" << i << ": " << ans[i] << endl;
    }
} // 