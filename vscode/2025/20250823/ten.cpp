#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int N = 3e5 + 10;

int n, m, ans;
int a[N];

struct node {
    int pos, w;
} tree[N * 4];

void pushup(int id) {
    if (tree[id * 2].w >= tree[id * 2 + 1].w) tree[id] = tree[id * 2];
    else tree[id] = tree[id * 2 + 1];
}

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = { l, a[l] };
        return ;
    }

    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    pushup(id);
}

void update(int id, int l, int r, int x, int v) {
    if (l == r) {
        tree[id] = { l, v };
        return ;
    }

    int mid = (l + r) >> 1;
    if (x <= mid) update(id * 2, l, mid, x, v);
    else update(id * 2 + 1, mid + 1, r, x, v);

    pushup(id);
}

int query(int id, int l, int r, int x) {
    if (l == r) return tree[id].w;

    int mid = (l + r) >> 1;
    if (x <= mid) return query(id * 2, l, mid, x);
    else return query(id * 2 + 1, mid + 1, r, x);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        // cout << tree[1].w << " ";
        update(1, 1, n, tree[1].pos, tree[1].w / 2);
    }

    for (int i = 1; i <= n; i++)
        ans += query(1, 1, n, i);

    cout << ans << endl;

    return 0;
}