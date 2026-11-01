#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct node { ll x, y; } p[N * 2];

int n;

int half(node u) {
    if (u.y > 0 || (u.y == 0 && u.x > 0))
        return 0;
    return 1;
}

ll cross(node a, node b) {
    return a.x * b.y - a.y * b.x;
}

ll dot(node a, node b) {
    return a.x * b.x + a.y * b.y;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    
    sort(p + 1, p + n + 1, [](node u, node v) {
        int whu = half(u), whv = half(v);
        if (whu != whv) return whu < whv;

        ll val = cross(u, v);
        if (val != 0) return val > 0;

        return u.x * u.x + u.y * u.y < v.x * v.x + v.y * v.y;
    });

    for (int i = 1; i <= n; i++)
        p[n + i] = p[i];

    int ans = 0;
    for (int l = 1, r = 0; l <= n; l++) {
        if (r < l) r = l;

        for (; r < l + n;) {
            ll c = cross(p[l], p[r]);
            ll d = dot(p[l], p[r]);

            if (c > 0 || (c == 0 && d > 0))
                r++;
            else 
                break;
        }

        ans = max(ans, r - l);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    while (T--) solve();

    return 0;
}