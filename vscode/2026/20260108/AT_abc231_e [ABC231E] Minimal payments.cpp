#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x, ans, a[65];
signed main() {
    scanf("%lld%lld", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = n; i >= 1; i--) {
        ans += x / a[i], x %= a[i];  //取这个硬币后的x
        if (a[i] - x < x - a[i - 1])
            ans++, x = a[i] - x;  //如果当前硬币较优
    }
    printf("%lld", ans);
    return 0;
}