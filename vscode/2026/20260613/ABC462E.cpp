#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a, b, ex, ey;
ll work(ll x, ll y, ll a, ll b) {
    x = abs(x), y = abs(y);
    if (x < y) swap(x, y);
    
    ll way1 = min(2 * a, 2 * b);
    ll way2 = min(a + b, 2 * way1);
    
    return y * way1 + ((x - y) / 2) * way2;
}

void solve() {
    cin >> a >> b >> ex >> ey;
    
    ll ans = 0;
    if ((abs(ex) + abs(ey)) % 2 == 0) {
        ans = work(ex, ey, a, b);
    } else {
        ll res1 = a + work(ex - 1, ey, a, b);
        ll res2 = a + work(ex + 1, ey, a, b);
        ll res3 = b + work(ex, ey - 1, a, b);
        ll res4 = b + work(ex, ey + 1, a, b);
        ans = min({ res1, res2, res3, res4 });
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T; cin >> T;
    while (T--) solve();
    return 0;
}