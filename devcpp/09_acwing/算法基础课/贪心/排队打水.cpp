#include <bits/stdc++.h>
#define int long long
#define maxn 100010
using namespace std;

int n, ans, a[maxn];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) ans += a[i] * (n - i);
    cout << ans << endl;
    return 0;
}
