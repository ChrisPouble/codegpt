#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    
    long long all = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    long long large = (r1 + r2) * (r1 + r2);
    long long small = (r1 - r2) * (r1 - r2);
    
    if (all >= small && all <= large) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    int T; cin >> T;
    while (T--) solve();

    system("pause");
    return 0;
}