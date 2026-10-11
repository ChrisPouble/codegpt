#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int N = 1e6 + 10;

int n, q;
int a[N], sum[N], qs[N];

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + max(a[i - 1] - a[i], 0ll);
        qs[i] = qs[i - 1] + sum[i];
    }

    int l, r;
    while (q--) {
        cin >> l >> r;

        if (l == r) {
            cout << 0 << endl;
            continue;
        }

        cout << qs[r] - qs[l] << endl;
    }
    
    system("pause");

    return 0;
}