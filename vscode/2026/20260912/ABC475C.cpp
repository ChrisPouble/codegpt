#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 8e3 + 10;

int n, S; ll L, a[N], pre[N];

ll dis(int l, int r) { return pre[r - 1] - pre[l - 1]; }

int main() {
    cin >> n >> S >> L;

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int ans = 0;
    for (int l = 1; l <= S; l++) {
        for (int r = S; r <= n; r++) {
            if (dis(l, S) * 2 + dis(S, r) <= L)
                ans = max(ans, r - l + 1);
            if (dis(S, r) * 2 + dis(l, S) <= L)
                ans = max(ans, r - l + 1);
        }
    }

    cout << ans << endl;

    return 0;
}