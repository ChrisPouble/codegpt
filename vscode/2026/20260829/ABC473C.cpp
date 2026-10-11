#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, k, a[N];
map <int, int> cnt;

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int mx = 0, cmx = 0;
    for (int i = 1; i <= k; i++) {
        if (mx <= cnt[i])
            cmx = mx, mx = cnt[i];
        else if (cmx <= cnt[i])
            cmx = cnt[i];
    }

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        if (cnt[i] == mx)
            ans++;
        else if (cnt[i] + 1 >= mx)
            ans++;
    }
    
    cout << ans << endl;
    return 0;
}