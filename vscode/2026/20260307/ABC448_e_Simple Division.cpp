#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 10;
const int mod = 10007;

int n, m;

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
    cin >> n >> m;

    int A1 = 0, A2 = 0;
    // A1 存 n mod 10007
    // A2 存 n mod m

    ll inv_9 = power(9, mod - 2, mod);
    for (int i = 1, c, l; i <= n; i++) {
        cin >> c >> l;

        ll p10 = power(10, l, mod);
        ll a1 = c * ((p10 - 1 + mod) % mod * inv_9) % mod;
        A1 = (A1 * p10 + a1) % mod;

        ll m10 = power(10, l, m), m10_9 = power(10, l, 9 * m);
        ll a2 = c * ((m10_9 - 1 + 9 * m) % (9 * m) / 9) % m;
        A2 = (A2 * m10 % m + a2) % m;
    }

    cout << (A1 - A2 + mod) % mod * power(m, mod - 2, mod) % mod << endl;
	
    return 0;
}
