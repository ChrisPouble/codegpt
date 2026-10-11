#include <bits/stdc++.h>
#define maxn 300010
#define int long long
using namespace std;

int n, m, ans = -LONG_LONG_MAX, h = 0, t = 0, a[maxn], q[maxn], s[maxn], f[maxn];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        int x = s[i];
        while(h <= t && i - q[h] > m) h++;
        f[i] = x - s[q[h]];
        // if(i <= m) f[i] = max(f[i], s[i]);
        while(h <= t && x <= s[q[t]]) t--;
        q[++t] = i;
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
