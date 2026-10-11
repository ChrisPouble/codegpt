#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int N = 1e6 + 10;
const int mod = 998244353;

int a, n, ans;
int f[N];

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> a >> n;

    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * 10 % mod;

    for (int i = n, j = 0; i >= 1; i--, j++) {
        ans = (ans + f[j] * i * a) % mod;
    }
    
    // for (int i = 1, now = 0; i <= n; i++) {
    //     now = now * 10 + a;
    //     ans = (ans + now) % mod;
    // }

    cout << ans << endl;

    system("pause");

    return 0;
}