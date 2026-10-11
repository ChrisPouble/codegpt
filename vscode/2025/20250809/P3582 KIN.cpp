#include <bits/stdc++.h>
using namespace std;

#define int long long // 记得开 long long，不然...
const int N = 1e6 + 10;

int n, m, ans;
int f[N], w[N];
int last[N], pre[N];

struct node {
    int lv, rv;
    int sumv, val;
} seg[N * 4];

void pushup(int id) {
    seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
    seg[id].lv = max(seg[id * 2].lv, seg[id * 2].val + seg[id * 2 + 1].lv);
    seg[id].rv = max(seg[id * 2 + 1].rv, seg[id * 2 + 1].val + seg[id * 2].rv);
    seg[id].sumv = max({seg[id * 2].sumv, seg[id * 2 + 1].sumv, seg[id * 2].rv + seg[id * 2 + 1].lv});
    // 这里要注意，是子节点的 sumv，不是 lv / rv，不然毁一生
}

void update(int id, int l, int r, int x, int v) {
    if (l == r) {
        seg[id] = { v, v, v, v };
        return ;
    }

    int mid = (l + r) >> 1;
    if (x <= mid) update(id * 2, l, mid, x, v);
    if (x > mid) update(id * 2 + 1, mid + 1, r, x, v);

    pushup(id);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= m; i++) cin >> w[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = last[f[i]], last[f[i]] = i;
        if (pre[i]) update(1, 1, n, pre[i], -w[f[i]]);
        if (pre[pre[i]] && pre[i]) update(1, 1, n, pre[pre[i]], 0);
        update(1, 1, n, i, w[f[i]]);
        ans = max(ans, seg[1].sumv);
    }

    cout << ans << endl;
    return 0;
}