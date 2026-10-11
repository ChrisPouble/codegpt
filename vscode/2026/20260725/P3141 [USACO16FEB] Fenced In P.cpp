#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 7e5 + 10;

ll A, B, n, m;
ll a[N], aa[N], b[N], bb[N], sum[N];

int main() {
    cin >> A >> B >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> aa[i];
    
    for (int i = 1; i <= m; i++)
        cin >> bb[i];
    
    sort(aa + 1, aa + n + 1);
    sort(bb + 1, bb + m + 1);

    aa[n + 1] = A, bb[m + 1] = B;
    for (int i = 1; i <= n + 1; i++)
        a[i] = aa[i] - aa[i - 1];
    
    for (int i = 1; i <= m + 1; i++)
        b[i] = bb[i] - bb[i - 1];
    
    n++, m++;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    
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