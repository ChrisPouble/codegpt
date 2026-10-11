#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;

int n;
int minv[4 * N], f[N];
int Lat[N], Rat[N];
int LRE[N], RRE[N];
vector<int> Remove[N];

struct node {
    int x, h;
} d[N];

bool cmp(node a, node b) {
    if (a.x == b.x) return a.h > b.h;
    return a.x < b.x;
}

void pushup(int id) { minv[id] = min(minv[id * 2], minv[id * 2 + 1]); }

void update(int id, int l, int r, int x, int v) {
    if (l == r) {
        minv[id] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(id * 2, l, mid, x, v);
    else update(id * 2 + 1, mid + 1, r, x, v);
    pushup(id);
}

int query(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) return minv[id];
    int mid = (l + r) >> 1, ans = inf;
    if (x <= mid) ans = min(ans, query(id * 2, l, mid, x, y));
    if (y > mid) ans = min(ans, query(id * 2 + 1, mid + 1, r, x, y));
    return ans;
}

void solve() {
	memset(minv, 0x3f, sizeof(minv)); 
    for (int i = 1; i <= n; i++)
        cin >> d[i].x >> d[i].h;

    sort(d + 1, d + n + 1, cmp);

    int m = 0;
    for (int i = 1; i <= n; i++) {
        if (m > 0 && d[m].x == d[i].x) continue;
        d[++m] = d[i];
    }
    
    n = m;

    for (int i = 0; i <= n; i++) {
        f[i] = inf;
        Remove[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        Lat[i] = i;
        int limit = d[i].x - d[i].h;
        while (Lat[i] > 1 && d[Lat[i] - 1].x >= limit) {
            limit = min(limit, LRE[Lat[i] - 1]);
            Lat[i] = Lat[Lat[i] - 1];
        }
        LRE[i] = limit;
    }

    for (int i = n; i >= 1; i--) {
        Rat[i] = i;
        int limit = d[i].x + d[i].h;
        while (Rat[i] < n && d[Rat[i] + 1].x <= limit) {
            limit = max(limit, RRE[Rat[i] + 1]);
            Rat[i] = Rat[Rat[i] + 1];
        }
        RRE[i] = limit;
    }

    f[0] = 0;

    for (int i = 1; i <= n; i++) {
        // 基础代价是 f[i - 1] + 1，有效期持续到 R[i]
        update(1, 1, n, i, f[i - 1] + 1);
        Remove[Rat[i]].push_back(i);
		
		// 考虑 i 往左边倒 
        f[i] = min(f[i], f[Lat[i] - 1] + 1);
		
		// 考虑 j 往右边倒 
        f[i] = min(f[i], query(1, 1, n, 1, i));
		
		// 只能波及到 i 的右倒决策点要被扔掉，因为其不会对后面的转移产生贡献 
        for (int idx : Remove[i]) update(1, 1, n, idx, inf);
    }

    cout << f[n] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while (cin >> n) solve();
    return 0;
}