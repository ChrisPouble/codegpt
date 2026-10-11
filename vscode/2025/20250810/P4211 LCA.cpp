#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 5e5 + 10;
const int mod = 201314;

int cnt;
struct node {
    int u, v, w;
    int id;
} Q[N];

struct tree {
    int sum, lzy;
} seg[N * 4];

int n, m, ans[N];
int fa[N], dep[N], sz[N], son[N];
int top[N], id[N], idx;

vector<int> linker[N];

void add(int x, int y) { linker[x].push_back(y); }
bool cmp(node x, node y) { return x.u < y.u; }

void pushup(int id) {
    seg[id].sum = seg[id * 2].sum + seg[id * 2 + 1].sum;
}

void pushdown(int id, int l, int r) {
    if (!seg[id].lzy) return ;

    int mid = (l + r) >> 1;
    seg[id * 2].sum += seg[id].lzy * (mid - l + 1);
    seg[id * 2 + 1].sum += seg[id].lzy * (r - mid);
    seg[id * 2].lzy += seg[id].lzy;
    seg[id * 2 + 1].lzy += seg[id].lzy;

    seg[id].lzy = 0;
}

void update(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        seg[id].sum += r - l + 1;
        seg[id].lzy++;
        return ;
    }

    pushdown(id, l, r);

    int mid = (l + r) >> 1;
    if (x <= mid) update(id * 2, l, mid, x, y);
    if (y > mid) update(id * 2 + 1, mid + 1, r, x, y);

    pushup(id);
}

int query(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) return seg[id].sum;

    pushdown(id, l, r);

    int mid = (l + r) >> 1, res = 0;
    if (x <= mid) res += query(id * 2, l, mid, x, y);
    if (y > mid) res += query(id * 2 + 1, mid + 1, r, x, y);

    return res;
}

void dfs1(int x) {
    dep[x] = dep[fa[x]] + 1, sz[x] = 1;
    for (int v : linker[x]) {
        dfs1(v);
        sz[x] += sz[v];
        if (sz[son[x]] < sz[v]) son[x] = v;
    }
}

void dfs2(int x, int t) { // t 指 top
    top[x] = t, id[x] = ++idx;
    if (!son[x]) return ;
    dfs2(son[x], t);
    for (int v : linker[x]) {
        if (v == fa[x] || v == son[x]) continue;
        dfs2(v, v);
    }
}

int query_path(int x, int y) {
    int res = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        res += query(1, 1, idx, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    res += query(1, 1, idx, id[y], id[x]);
    return res;
}

void update_path(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, idx, id[top[x]], id[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    update(1, 1, idx, id[y], id[x]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        fa[i]++;
        add(fa[i], i);
    }

    dfs1(1), dfs2(1, 1);

    for (int i = 1, l, r, z; i <= m; i++) {
        cin >> l >> r >> z;
        l++, r++, z++;
        Q[++cnt] = { l - 1, z, -1, i };
        Q[++cnt] = { r, z, 1, i };
    }

    sort(Q + 1, Q + cnt + 1, cmp);

    for (int i = 1, now = 1; i <= n; i++) {
        while (Q[now].u == 0) now++;
        update_path(1, i);
        while (Q[now].u == i) {
            ans[Q[now].id] += Q[now].w * query_path(1, Q[now].v);
            now++;
        }
    }

    for (int i = 1; i <= m; i++)
        cout << (ans[i] % mod + mod) % mod << endl;
    return 0;
}