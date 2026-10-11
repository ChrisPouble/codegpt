#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;
const int mod = 1e9 + 7;

ll n, a[N], b[N], A[N], B[N], SA[N], SB[N], SAB[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        A[i] = (A[i - 1] + a[i]) % mod;
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        B[i] = (B[i - 1] + b[i]) % mod;
    }

    for (int i = 1; i <= n; i++) {
        SA[i] = (SA[i - 1] + A[i]) % mod;
        SB[i] = (SB[i - 1] + B[i]) % mod;
        SAB[i] = (SAB[i - 1] + (A[i] * B[i]) % mod) % mod;
    }
    
    ll ans = 0ll;
    for (int i = 1; i <= n; i++)
        ans = (ans + ((SAB[n] - SAB[i - 1]) + mod) % mod) % mod;
    
    for (int i = 1; i <= n; i++)
        ans = (ans + (((n - i + 1) * A[i - 1]) % mod * B[i - 1]) % mod) % mod;
    
    for (int i = 1; i <= n; i++)
        ans = ((ans - (B[i - 1] * ((SA[n] - SA[i - 1] + mod) % mod)) % mod) + mod) % mod;
    
    for (int i = 1; i <= n; i++)
        ans = ((ans - (A[i - 1] * ((SB[n] - SB[i - 1] + mod) % mod)) % mod) + mod) % mod;
    
    cout << ans << endl;
    return 0;
}