#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[100010], sumv[4 * 100010], lazy[4 * 100010]; //lazy是用来更新线段树区间的数组 
void pushup(int id) { //线段树主要部分 
	sumv[id] = sumv[id * 2] + sumv[id * 2 + 1];
}

void pushdown(int id, int l, int r) { //线段树主要部分 
	if(lazy[id] != 0) { //如果不为0 
		int mid = (l + r) >> 1;
		sumv[id * 2] = sumv[id * 2] + lazy[id] * (mid - l + 1); //加上 
		sumv[id * 2 + 1] = sumv[id * 2 + 1] + lazy[id] * (r - mid); //加上 
		lazy[id * 2] += lazy[id]; //上面清完后，下面也要把这个值加上 
		lazy[id * 2 + 1] += lazy[id];
		lazy[id] = 0; //清零 
	}
}

void build(int id, int l, int r) {
	if(l == r) { //当区间大小只有1个的时候 
		sumv[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid); //遍历左子树 
	build(id * 2 + 1, mid + 1, r); //遍历右子树 
	pushup(id); //更新 
}

void update(int id, int l, int r, int x, long long y, long long v) {
	if(x <= l && r <= y) { //如果当前区间已经被待更新区间包含了 
		sumv[id] = sumv[id] + v * (r - l + 1); //则更新区间和 
		lazy[id] = lazy[id] + v; //并且lazy值也要更新 
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(id, l, r); //现在，要把这个数的lazy值拿出来用了 
	if(x <= mid) update(id * 2, l, mid, x, y, v); //遍历左子树 
	if(y > mid) update(id * 2 + 1, mid + 1, r, x, y, v); //遍历右子树 
	pushup(id); //更新区间和 
}

long long query_sum(int id, int l, int r, int x, long long y) {
	if(x <= l && r <= y) return sumv[id]; //如果当前区间已经被待更新区间包含了，说明找到了 
	int mid = (l + r) >> 1;
	long long ans = 0;
	pushdown(id, l, r); //现在，要把这个数的lazy值拿出来用了 
	if(x <= mid) ans += query_sum(id * 2, l, mid, x, y); //遍历左子树 
	if(y > mid) ans += query_sum(id * 2 + 1, mid + 1, r, x, y); //遍历右子树 
	return ans; //返回找到的区间和 
}

signed main() {
	ios::sync_with_stdio(0); //关闭输入流 
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n); //初始化
	while(m--) {
		char d;
		long long x, y, k;
		cin >> d >> x >> y;
		if(d == "C") {
			cin >> k;
			update(1, 1, n, x, y, k);
		} else cout << query_sum(1, 1, n, x, y) << "\n"; //"\n"比endl快亿点点 
	}
	return 0;
}
