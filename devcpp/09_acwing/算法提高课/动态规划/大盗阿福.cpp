#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int T, n, a[maxn], f[maxn];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[1] = a[1], f[2] = max(a[1], a[2]);
    for (int i = 3; i <= n; i++) f[i] = max(f[i - 2] + a[i], f[i - 1]);
    printf("%d\n", f[n]);
}

signed main() {
    cin >> T;
    while(T--) solve();
    return 0;
}
