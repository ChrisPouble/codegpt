#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
const int M = 1e6 + 10;

int n, tim, tree1[M], tree2[M], tree3[M], tree4[M], tree5[M];
struct node { int l, r; } a[N], p[N];

int lowbit(int x) { return x & -x; }

int query1(int x) {
    int res = 0;
    while (x) { res += tree1[x], x -= lowbit(x); }
    return res;
}

int query2(int x) {
    int res = 0;
    while (x) { res += tree2[x], x -= lowbit(x); }
    return res;
}

int query3(int x) {
    int res = 0;
    while (x) { res += tree3[x], x -= lowbit(x); }
    return res;
}

int query4(int x) {
    int res = 0;
    while (x) { res += tree4[x], x -= lowbit(x); }
    return res;
}

int query5(int x) {
    int res = 0;
    while (x) { res += tree5[x], x -= lowbit(x); }
    return res;
}

void add1(int x, int c) {
    while (x < M) { tree1[x] += c, x += lowbit(x); }
}

void add2(int x, int c) {
    while (x < M) { tree2[x] += c, x += lowbit(x); }
}

void add3(int x, int c) {
    while (x < M) { tree3[x] += c, x += lowbit(x); }
}

void add4(int x, int c) {
    while (x < M) { tree4[x] += c, x += lowbit(x); }
}

void add5(int x, int c) {
    while (x < M) { tree5[x] += c, x += lowbit(x); }
}

bool cmp(node x, node y) {
    if (x.l != y.l) return x.l < y.l;
    return x.r < y.r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> tim;
    
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        if (a[i].r - a[i].l >= tim) p[++tot] = a[i];
    }

    sort(p + 1, p + tot + 1, cmp);

    long long ans = 0ll;
    for (int i = 1; i <= tot; i++) {
        add1(p[i].l, 1);
        add2(p[i].r, p[i].l);
        add3(p[i].l, p[i].l);
        add4(p[i].r, 1);
        add5(p[i].r, p[i].r - p[i].l);
    }
    
    for (int i = 1; i <= tot; i++) {
        add1(p[i].l, -1);
        add2(p[i].r, -p[i].l);
        add3(p[i].l, -p[i].l);
        add4(p[i].r, -1);
        add5(p[i].r, -(p[i].r - p[i].l));
        ans += (query1(p[i].r - tim) * (p[i].r - tim + 1) - query3(p[i].r - tim));
        ans -= (query4(p[i].r) * (p[i].r - tim + 1) - query2(p[i].r));
        ans += query5(p[i].r) + query4(p[i].r) * (-tim + 1);
        // cout << ans << " ";
    }

    cout << ans << endl;

    return 0;
}