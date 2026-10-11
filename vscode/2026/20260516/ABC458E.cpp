#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e6 + 10;
const int mod = 998244353;

int x1, x2, x3, ans;
int fac[N], infac[N];

int ksm(int a, int b, int md) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % md;
        a = a * a % md;
        b >>= 1;
    }
    return res;
}

int getc(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return fac[a] % mod * infac[b] % mod * infac[a - b] % mod;
}

signed main() {
    cin >> x1 >> x2 >> x3;

    fac[0] = infac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = ksm(fac[i], mod - 2, mod) % mod;
    }

    int end = min(x1 + x3 - 1, x2);
    for (int k = 1; k <= end; k++) {
        int qun = getc(x1 + x2 + x3 - k, x1 + x3);
        int sum = 0;

        if (k & 1) sum = (sum + 2 * getc(x1 - 1, (k - 1) / 2) * getc(x3 - 1, (k + 1) / 2 - 1)) % mod;
        else {
            sum = (sum + getc(x1 - 1, k / 2) * getc(x3 - 1, k / 2 - 1)) % mod;
            sum = (sum + getc(x1 - 1, (k - 2) / 2) * getc(x3 - 1, (k + 2) / 2 - 1)) % mod;
        }

        ans = (ans + qun * sum % mod) % mod;
    }

    cout << ans << endl;

    // system("pause");
    return 0;
}