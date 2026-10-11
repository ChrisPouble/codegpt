// Problem: ATcoder - Restricted Permutation
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_g
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e3 + 10;
const int mod = 998244353;

int n; string s;
ll f[N], g[N];

int main() {
    cin >> n >> s;
    s = ' ' + s;

    if (s[1] == 'x' || s[n] == 'x') { cout << 0 << endl; return 0; }

    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
    }

    for (int i = 1; i <= n; i++) {
        g[i] = f[i + 1];
        for (int k = 1; k < i; k++)
            g[i] = ((g[i] - f[i - k + 1] * g[k]) % mod + mod) % mod;
    }

    int lst = 1; ll ans = 1;
    for (int i = 2; i <= n; i++) {
        if (s[i] == 'o') {
            ans = ans * g[i - lst] % mod;
            lst = i;
        }
    }

    cout << ans << endl;

    return 0;
}