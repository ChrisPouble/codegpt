#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;

int T, n, f[N];
struct node {
    int s, e, l;
} a[N];

bool cmp(node x, node y) {
    return x.s * y.l <= x.l * y.s;
}

void solve(int x) {
    cin >> n;
    memset(f, 0, sizeof(f));
    int t = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].e >> a[i].l;
        t += a[i].s;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = t; j >= 0; j--)
            if(j >= a[i].s) f[j] = max(f[j], f[j - a[i].s] + a[i].e - (j - a[i].s) * a[i].l);
    for (int i = 0; i <= t; i++) ans = max(ans, f[i]);
    cout << "Case #" << x << ": " << ans << endl;
}

signed main() {
    cin >> T;
    for (int i = 1; i <= T; i++) solve(i);
    return 0;
}
