#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int inf = 1e9;

int n, Q, pre[N];
string str;

struct SegTree {
    struct TreeNode { int mn, lzy; };

    TreeNode tree[N * 4];

    TreeNode pushup(TreeNode ls, TreeNode rs) {
        return { min(ls.mn, rs.mn), 0 };
    }

    void pushdown(int id) {
        if (tree[id].lzy == 0) return ;
        tree[id << 1].mn += tree[id].lzy;
        tree[id << 1 | 1].mn += tree[id].lzy;
        tree[id << 1].lzy += tree[id].lzy;
        tree[id << 1 | 1].lzy += tree[id].lzy;
        tree[id].lzy = 0;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id].mn = pre[l];
            return ;
        }

        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        tree[id] = pushup(tree[id << 1], tree[id << 1 | 1]);
    }

    void update(int id, int l, int r, int x, int y, int val) {
        if (x <= l && r <= y) {
            tree[id].mn += val;
            tree[id].lzy += val;
            return ;
        }

        pushdown(id);

        int mid = (l + r) >> 1;
        if (x <= mid) update(id << 1, l, mid, x, y, val);
        if (y > mid)  update(id << 1 | 1, mid + 1, r, x, y, val);
        tree[id] = pushup(tree[id << 1], tree[id << 1 | 1]);
    }

    int query(int id, int l, int r, int x, int y) {
        if (x <= l && r <= y) { return tree[id].mn; }

        pushdown(id);

        int mid = (l + r) >> 1; int ans = 1e9;
        if (x <= mid) ans = min(ans, query(id << 1, l, mid, x, y));
        if (y > mid)  ans = min(ans, query(id << 1 | 1, mid + 1, r, x, y));
        
        return ans;
    }
} seg;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> str; str = ' ' + str;
    for (int i = 1; i <= n; i++) {
        pre[i] = (str[i] == 'A' ? 1 : -1);
        pre[i] += pre[i - 1];
    }

    seg.build(1, 1, n);

    cin >> Q;
    while (Q--) {
        int opt, l, r, id; string v; cin >> opt;
        
        if (opt == 1) {
            cin >> id >> v;
            int oldval = (str[id] == 'A' ? 1 : -1);
            int newval = (v == "A" ? 1 : -1);
            seg.update(1, 1, n, id, n, newval - oldval);
            str[id] = (v == "A" ? 'A' : 'B');
        } else {
            cin >> l >> r;
            int base = (l == 1 ? 0 : seg.query(1, 1, n, l - 1, l - 1));
            int now = seg.query(1, 1, n, l, r);
            cout << (now >= base ? "Yes\n" : "No\n");
        }
    }

    return 0;
}