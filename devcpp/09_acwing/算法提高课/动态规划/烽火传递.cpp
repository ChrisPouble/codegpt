#include <bits/stdc++.h>
#define maxn 200010
#define int long long
using namespace std;

int n, m, ans, h = 0, t = 0, a[maxn], q[maxn], f[maxn];
signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        while(h <= t && i - q[h] > m) h++;
        f[i] = a[i] + f[q[h]];
        while(h <= t && f[i] <= f[q[t]]) t--;
        q[++t] = i;
    }
    if(n - q[h] >= m) h++;
    cout << f[q[h]] << endl;
    return 0;
}
