#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 5e3 + 10;

int T;

int n, m, a[N];

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int sum = 0;
    for (int i = 1; i < m; i++)
        sum += a[i];
    
    for (int i = m; i <= n; i++) {
        if (sum > a[i]) {
            cout << "YES\n";
            return ;
        }
        sum += a[i], sum -= a[i - m + 1];
    }

    cout << "NO\n";
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--) solve();

    system("pause");
    return 0;
}