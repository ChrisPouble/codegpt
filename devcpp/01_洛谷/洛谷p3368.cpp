#include <bits/stdc++.h>
#define maxn 500010
#define int long long
using namespace std;

int n, q, a[maxn], sumv[maxn * 4], lazy[maxn * 4];
void pushup(int id) {
	sumv[id] = sumv[id * 2] + sumv[id * 2 + 1];
}

void pushdown(int id, int l, int r) {
	if(lazy[id] != 0) {
		int mid = (l + r) >> 1;
		sumv[id * 2] = sumv[id * 2] + lazy[id] * (mid - l + 1);
		sumv[id * 2 + 1] = sumv[id * 2 + 1] + lazy[id] * (r - mid);
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		lazy[id] = 0;
	}
}

void build(int id, int l, int r) {
	lazy[id] = 0;
	if(l == r) {
		sumv[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pushup(id);
}

void update(int id, int l, int r, int x, int y, int v) {
	if(x <= l && r <= y) {
		sumv[id] += (r - l + 1) * v;
		lazy[id] += v;
		return;
	}
	pushdown(id, l, r);
	int mid = (l + r) >> 1;
	if(x <= mid) update(id * 2, l, mid, x, y, v);
	if(y > mid) update(id * 2 + 1, mid + 1, r, x, y, v);
	pushup(id);
}

int query(int id, int l, int r, int x) {
	if(l == r) return sumv[id];
	pushdown(id, l, r); 
	int mid = (l + r) >> 1, ans = 0;
	if(x <= mid) ans += query(id * 2, l, mid, x);
	if(x > mid) ans += query(id * 2 + 1, mid + 1, r, x);
	pushup(id);
	return ans;
}

signed main() {
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	build(1, 1, n);
	while (q--) {
		int d, x;
		scanf("%lld%lld", &d, &x);
		if(d == 1) {
			int y, k;
			scanf("%lld%lld", &y, &k);
			update(1, 1, n, x, y, k);
		} else printf("%lld\n", query(1, 1, n, x));
	}
	return 0;
}
