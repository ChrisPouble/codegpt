#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n; ll a[35];

void solve() {
    cin >> n;

    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) flag = 0;
    }
    
    if (flag) { cout << "0\n"; return ; }
    if (n == 1) { cout << "1\n"; return ; }
    
    ll sup = 0;
    bool can = true;
    
    for (int i = 1; i < n; i++) {
        ll d = a[i] - 2 * a[i + 1];
        if (d < 0) { can = 0; break; }
        sup = max(sup, d);
    }
    
    if (!can) { cout << "-1\n"; return ; }
    if (sup == 0) {
        cout << 1 << "\n";
    } else {
        cout << sup << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}