// Problem: ATcoder - Sum of Average
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 10;
const int mod = 998244353;

int n;
ll a[N], S[N], T[N];

ll ksm(ll x, ll y) {
    if (y == 0) return 1;

    ll tmp = ksm(x, y >> 1);

    if (y & 1) return tmp * tmp % mod * x % mod;
    else return tmp * tmp % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        S[i] = (a[i] + S[i - 1]) % mod;
        T[i] = (S[i] + T[i - 1]) % mod;
    }

    ll P = 0, Q = 1; // P / Q
    for (int p = 1; p <= n; p++) {
        ll val = ((T[n] - T[p - 1] - T[n - p]) % mod + mod) % mod;
        P = (P * p % mod + Q * val % mod) % mod;
        Q = Q * p % mod;
    }
    
    // cout << P << "/" << Q << endl;
    cout << ksm(Q % mod, mod - 2) * P % mod << endl;

    return 0;
}