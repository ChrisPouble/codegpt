// Problem: CF1738E Balance Addicts
// Contest: Codeforces - Global Round 22
// URL: https://codeforces.com/problemset/problem/1738/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;
const int N = 2e5 + 10;

ll a[N];
ll fac[N], inv[N];

ll ksm(ll base, ll exp) {
    ll res = 1ll;
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
        fac[i] = (fac[i - 1] * i) % mod;
    }
    
    inv[N - 1] = ksm(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

void solve() {
    int n; cin >> n;
    
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) flag = 0;
    }

    if (flag) { cout << ksm(2, n - 1) << "\n"; return ; }

    int l = 0, r = n - 1;

    int head_zero = 0;
    while (l <= r && a[l] == 0) { head_zero++, l++; }
    
    int tail_zero = 0;
    while (r >= l && a[r] == 0) { tail_zero++, r--; }

    ll ans = C(head_zero + tail_zero, head_zero);

    while (l < r) {
        ll sumL = a[l], sumR = a[r];

        while (l < r && sumL != sumR) {
            if (sumL < sumR) {
                l++, sumL += a[l];
            } else {
                r--, sumR += a[r];
            }
        }

        if (l >= r) break;

        int i = l, j = r;
        int x = 0, y = 0;

        while (i + 1 < j && a[i + 1] == 0)
            x++, i++;
        
        while (j - 1 > i && a[j - 1] == 0)
            y++, j--;

        if (i + 1 == j) {
            ans = (ans * ksm(2, x + y + 1)) % mod;
            break;
        } else {
            ans = (ans * C(x + y + 2, x + 1)) % mod;
            l = i + 1, r = j - 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
	
	int T; cin >> T;
	while (T--) solve();

    return 0;
}