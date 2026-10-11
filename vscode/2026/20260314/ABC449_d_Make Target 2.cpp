#include <bits/stdc++.h>
#define int long long
using namespace std;

int l, r, u, v;

int get(int l, int r) {
    if (l % 2 && r % 2) return ((r - 1) - (l + 1)) / 2 + 1;
    if (!(l % 2) && !(r % 2)) return (r - l) / 2 + 1;
    return (r - l - 1) / 2 + 1;
}

signed main() {
    cin >> l >> r >> u >> v;

    int ans = 0;
    for (int i = l; i <= r; i++) {
        int x = abs(i);
        
        if (!(i % 2)) {
            if (u >= 0) {
                if (x >= u && x <= v) ans += max(x - u + 1, 0ll);
                else if (x > v) ans += v - u + 1;
            } else if (u < 0 && v >= 0) {
                ans += min(x, abs(u));
                ans += min(x, abs(v));
                ans ++;
            } else if (v < 0) {
                if (x >= abs(v) && x <= abs(u)) ans += max(x - abs(v) + 1, 0ll);
                else if (x > abs(u)) ans += abs(u) - abs(v) + 1;
            }
        }
        
        if (u >= 0) {
            if (x >= u && x <= v) ans += max(get(x + 1, v), 0ll);
            else if (x < u) ans += max(get(u, v), 0ll);
        } else if (u < 0 && v >= 0) {
            if (x < abs(u)) ans += max(get(x + 1, abs(u)), 0ll);
            if (x < abs(v)) ans += max(get(x + 1, abs(v)), 0ll);
        } else if (v < 0) {
            if (x >= abs(v) && x <= abs(u)) ans += max(get(x + 1, abs(u)), 0ll);
            else if (x < abs(v)) ans += max(get(abs(v), abs(u)), 0ll);
        }
    }

    cout << ans << endl;

    return 0;
}
