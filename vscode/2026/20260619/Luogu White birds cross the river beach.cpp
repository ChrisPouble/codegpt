#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(int a1, int a2, int b1, int b2) {
    if (a1 * b2 >= a2 * b1) return 1;
    return 0;
}

void solve() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    if (cmp(a, x, b, y) && cmp(a, x, c, z)) cout << 1 << endl;
    else if (cmp(b, y, a, x) && cmp(b, y, c, z)) cout << 2 << endl;
    else if (cmp(c, z, a, x) && cmp(c, z, b, y)) cout << 3 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}