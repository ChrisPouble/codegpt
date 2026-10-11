#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
const int mod = 998244353;

int n, m, a[N], b[N];
int P[N], T[N], q[N * 2];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    int  Qsum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i],  Qsum += a[i] * i;
        q[i] = a[i] + q[i - 1];
    }

    for (int i = n + 1; i <= 2 * n; i++)
        q[i] = q[i - 1];

    for (int i = 1; i <= m; i++)
        cin >> b[i];

    for (int i = 1; i <= m; i++) 
        P[i] = b[i] * i;

    for (int i = 1; i <= m; i++) {
        if (i > n) {
            T[i] = 0;
            continue;
        }
        
        int j = i - 1, k = 0;
        for (; j <= n; j += i, k++) T[i] = (T[i] + (q[j] - q[max(0ll, j - i)]) * k) % mod;

        T[i] = (T[i] + (q[j] - q[max(0ll, j - i)]) * k) % mod;
    }

    // for (int i = 1; i <= m; i++) cout << T[i] << " ";
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + b[i] * Qsum) % mod;
        ans = ((ans - P[i] * T[i] % mod) % mod + mod) % mod;

        // cout << P[i] * sum * T[i] << " ";
    }

    cout << (ans % mod + mod) % mod << endl;

    system("pause");
    return 0;
}