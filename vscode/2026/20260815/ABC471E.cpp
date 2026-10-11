#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 10;
const ll mod = 998244353;

ll fac[N], inv[N];

ll qpow(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

void init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N - 1] = qpow(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

ll C(int n, int m) {
    if (m < 0 || n < m) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n, k; cin >> n >> k;

    ll sum1 = 0, sum2 = 0;

    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        x %= mod;
        sum1 = (sum1 + x) % mod;
        sum2 = (sum2 + x * x) % mod;
    }

    ll way1 = sum2 * C(n - 1, k - 1) % mod;
    ll way2 = (sum1 * sum1 % mod - sum2 + mod) % mod * C(n - 2, k - 2) % mod;

    cout << (way1 + way2) % mod << "\n";

    return 0;
}