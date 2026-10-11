#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e4 + 10;

int n, m, a[N];
int tree[N * 4], lazy[N * 4];

void pushdown(int id) {
    if (!lazy[id]) return ;
    lazy[id * 2] = lazy[id];
    lazy[id * 2 + 1] = lazy[id];
    tree[id * 2] = lazy[id];
    tree[id * 2 + 1] = lazy[id];
    lazy[id] = 0;
}

void build(int l, int r, int id) {
    if (l == r) {
        tree[id] = a[l];
        return ;
    }

    int mid = (l + r) >> 1;
    build(l, mid, id * 2);
    build(mid + 1, r, id * 2 + 1);
}

void update(int id, int l, int r, int x, int y, int v) {
    if (x <= l && r <= y) {
        lazy[id] = v;
        tree[id] = v;
        return ;
    }

    pushdown(id);

    int mid = (l + r) >> 1;
    if (x <= mid) update(id * 2, l, mid, x, y, v);
    if (y > mid) update(id * 2 + 1, mid + 1, r, x, y, v);
}

int query(int id, int l, int r, int x) {
    if (l == r) return tree[id];

    pushdown(id);

    int mid = (l + r) >> 1;
    if (x <= mid) return query(id * 2, l, mid, x);
    else return query(id * 2 + 1, mid + 1, r, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, n, 1);

    while (m--) {
        int l, r, v;
        cin >> l >> r >> v;

        update(1, 1, n, l, r, v);
    }

    for (int i = 1; i <= n; i++)
        cout << query(1, 1, n, i) << " ";

    // system("pause");
    return 0;
}