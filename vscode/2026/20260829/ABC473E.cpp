#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 10;

int n, k, f[N];
ll a[N], sum[N];

map <int, int> cnt, tot;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0; tot[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = max(tot[sum[i] % k] * (cnt[sum[i] % k] + 1), f[i - 1]);
        cnt[sum[i] % k] = max(cnt[sum[i] % k], f[i]);
        tot[sum[i] % k] = 1;
        ans = max(ans, f[i]);
        // cout << f[i] << " ";
    }

    cout << ans << endl;
    
    return 0;
}