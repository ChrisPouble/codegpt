#include <bits/stdc++.h>
#define maxn 50010
using namespace std;

int n, T, a[maxn], q[maxn], f[maxn];
bool check(int m) {
    int h = 0, t = 0;
    memset(q, 0, sizeof(q));
    for (int i = 1; i <= n; i++) {
        while(h <= t && i - q[h] > m) h++;
        f[i] = a[i] + f[q[h]];
        while(h <= t && f[i] <= f[q[t]]) t--;
        q[++t] = i;
    }
    if(n - q[h] >= m) h++;
    return f[q[h]] <= T;
}

signed main() {
    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid + 1)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
