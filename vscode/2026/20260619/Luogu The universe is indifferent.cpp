#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

struct flat {
    int x, y, id;
    int type;
} a[N];

int n, q;
int p[N], lst[N];
map <pair<int, int>, int> cnt;

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

pair<int, int> get(int i) {
    int b = a[i + 1].y - a[i].y;
    int d = a[i].x - a[i + 1].x;

    if (d == 0) return make_pair((b == 0 ? 0 : 1), d);

    int g = gcd(b, d);

    b /= g, d /= g;
    if (d < 0) b = -b, d = -d;

    return { b, d };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i, a[i].type = 1;
    }
    
    for (int i = 1; i < n; i++) {
        p[i] = p[i - 1];
        if (a[i].x == a[i + 1].x && a[i].y != a[i + 1].y)
            p[i]++;
    }

    int li = 0;
    pair<int, int> lv = {0, 0};

    int ldi = 0;
    for (int i = 1; i < n; i++) {
        auto res = get(i);
        if (res == make_pair(1, 0) || res == make_pair(0, 0)) {
            lst[i] = ldi;
        } else {
            if (li != 0 && res != lv) ldi = li;
            lv = res, li = i;
            lst[i] = ldi;
        }
    }

    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;

        if (p[r - 1] - p[l - 1] >= 1) cout << "No\n";
        else if (lst[r - 1] >= l) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}