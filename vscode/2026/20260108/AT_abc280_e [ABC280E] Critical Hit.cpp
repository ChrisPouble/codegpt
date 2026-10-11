#include <bits/stdc++.h>
#define int long long
#define mod 998244353
#define divmod 828542813
#define maxn 200010
using namespace std;

int n, p, f[maxn];
signed main() {
    cin >> n >> p;
    f[0] = 0, f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] =
            (p * divmod % mod * (f[i - 2] + 1) % mod + (100 - p) * divmod % mod * (f[i - 1] + 1) % mod) % mod;
    cout << f[n] % mod << endl;
    return 0;
}