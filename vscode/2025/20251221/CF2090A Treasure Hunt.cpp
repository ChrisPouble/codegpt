#include <bits/stdc++.h>
using namespace std;

int x, y, a;
void solve() {
    cin >> x >> y >> a;
    
    int lst = a % (x + y);
    if (lst < x) cout << "NO\n";
    else cout << "YES\n";

}

int main() {
    int T;
    cin >> T;

    while (T--) solve();
    return 0;
}