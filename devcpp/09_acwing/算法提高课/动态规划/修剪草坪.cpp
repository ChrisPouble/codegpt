#include <bits/stdc++.h>
#define maxn 300010
#define int long long
using namespace std;

int n, m, ans = 0, h = 0, t = 0, a[maxn], q[maxn], s[maxn], f[maxn];
int g(int x) {
    return f[max(0ll, x - 1)] - s[x];
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++) {
        while(h <= t && i - q[h] > m) h++;
        f[i] = max(s[i] + g(q[h]), f[i - 1]);
        while(h <= t && g(i) >= g(q[t])) t--;
        q[++t] = i;
    }
    cout << f[n] << endl;
    return 0;
}
