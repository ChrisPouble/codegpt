#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int T, n, q, m;
int p[N], tree[N << 2];

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int lc(int x) { return x << 1; }
int rc(int x) { return x << 1 | 1; }

void build(int x, int l, int r) {
    if (l == r) {
        tree[x] = p[l];
        return;
    }

    int mid = l + r >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);

    tree[x] = gcd(tree[lc(x)], tree[rc(x)]);
    return;
}

void update(int x, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[x] = val;
        return;
    }

    int mid = tl + tr >> 1;
    if (pos <= mid) update(lc(x), tl, mid, pos, val);
    else update(rc(x), mid + 1, tr, pos, val);

    tree[x] = gcd(tree[lc(x)], tree[rc(x)]);

    return;
}

int query(int x, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) return tree[x];

    int mid = tl + tr >> 1, tp1 = 0, tp2 = 0;
    if (ql <= mid) tp1 = query(lc(x), tl, mid, ql, qr);
    if (qr > mid) tp2 = query(rc(x), mid + 1, tr, ql, qr);

    if (tp1 && tp2) return gcd(tp1, tp2);
    else return tp1 + tp2;
}

void solve() {
    memset(tree, 0, sizeof(tree));
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    
    build(1, 1, n);
    for (int i = 1, opt; i <= q; i++) {
        cin >> opt;

        int ix, jx, iy, jy;
        int id, y;
        if (opt == 1) {
            cin >> ix >> jx >> iy >> jy;
            if (ix > iy) swap(ix, iy), swap(jx, jy);

            int d = query(1, 1, n, ix, iy);
            int u = p[ix] / d, v = p[iy] / d;
            if ((jx + u - 1) / u == (jy + v - 1) / v) puts("Yes");
            else puts("No");
        } else {
            cin >> id >> y;
            p[id] = y;
            update(1, 1, n, id, y);
        }
    }
}

int main() {
    // freopen("negg.in", "r", stdin);
    // freopen("negg.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}