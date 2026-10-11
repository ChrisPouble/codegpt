#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 7e5 + 10;

ll n, m, a[N], b[N], sum[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    
    ll ans = a[1] * (m - 1) + b[1] * (n - 1);

    for (int i = 1; i <= m; i++)
        sum[i] = sum[i - 1] + b[i];
    
    for (int i = 2; i <= n; i++) {
        int x = lower_bound(b + 2, b + 1 + m, a[i]) - b;
        ans += sum[x - 1] - sum[1];
        ans += (m - x + 1) * a[i];
    }

    cout << ans << endl;
    return 0;
}