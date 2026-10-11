#include <bits/stdc++.h>
#define maxn 100010
#define int long long //不开long long见祖宗 
#define endl "\n" //"\n"比endl快亿点点
using namespace std;

int n, m, p;
//lazy_add是用来更新线段树区间加法那一部分的数组，lazy_mul则是用来更新线段树区间乘法那一部分的数组
int a[maxn], sumv[4 * maxn], lazy_add[4 * maxn], lazy_mul[4 * maxn];
void pushup(int id) { //线段树主要部分
	sumv[id] = (sumv[id * 2] + sumv[id * 2 + 1]) % p;
}

void pushdown(int id, int l, int r) { //线段树主要部分
	int mid = (l + r) >> 1;
	//遍历左子树id * 2
	sumv[id * 2] = sumv[id * 2] * lazy_mul[id] % p; //先考虑乘法 
	sumv[id * 2] = (sumv[id * 2] + (mid - l + 1) * lazy_add[id]) % p; //再考虑加法 
	lazy_mul[id * 2] = (lazy_mul[id * 2] * lazy_mul[id]) % p; //更新自己下一个的lazy 
	lazy_add[id * 2] = (lazy_add[id * 2] * lazy_mul[id]) % p; //先考虑乘法 
	lazy_add[id * 2] = (lazy_add[id * 2] + lazy_add[id]) % p; //再考虑加法 
	//遍历右子树id * 2 + 1
	sumv[id * 2 + 1] = sumv[id * 2 + 1] * lazy_mul[id] % p; //同上 
	sumv[id * 2 + 1] = (sumv[id * 2 + 1] + (r - mid) * lazy_add[id]) % p;
	lazy_mul[id * 2 + 1] = (lazy_mul[id * 2 + 1] * lazy_mul[id]) % p;
	lazy_add[id * 2 + 1] = (lazy_add[id * 2 + 1] * lazy_mul[id]) % p;
	lazy_add[id * 2 + 1] = (lazy_add[id * 2 + 1] + lazy_add[id]) % p;
	//清零 
	lazy_mul[id] = 1, lazy_add[id] = 0;
}

void build(int id, int l, int r) {
	lazy_add[id] = 0;
	lazy_mul[id] = 1; //lzay_mul要初始化为1 
	if(l == r) { //当区间大小只有1个的时候
		sumv[id] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid); //遍历左子树
	build(id * 2 + 1, mid + 1, r); //遍历右子树
	pushup(id); //更新
}

//id代表这个节点在线段树里的编号，l和r表示当前区间，x和y表示待查找区间，v表示乘数 
void update_mul(int id, int l, int r, int x, int y, int v) {
	if(x <= l && r <= y) { //如果当前区间已经被待更新区间包含了
		sumv[id] = sumv[id] * v % p; //则更新区间和
		lazy_mul[id] = lazy_mul[id] * v % p; //并且lazy值也要更新
		lazy_add[id] = lazy_add[id] * v % p; //请注意，因为乘法的值会影响加法，所以在计算这一部分的时候加法也要算进去 
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(id, l, r); //现在，要把这个数的lazy值拿出来用了
	if(x <= mid) update_mul(id * 2, l, mid, x, y, v); //遍历左子树
	if(y > mid) update_mul(id * 2 + 1, mid + 1, r, x, y, v); //遍历右子树
	pushup(id); //更新区间和
}

void update_add(int id, int l, int r, int x, int y, int v) { //和上面差不多，只不过变成了加法 
	if(x <= l && r <= y) { //如果当前区间已经被待更新区间包含了
		sumv[id] = (sumv[id] + v * (r - l + 1)) % p; //则更新区间和
		lazy_add[id] = (lazy_add[id] + v) % p; //由于加法不影响乘法，所以直接算就可以了 
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(id, l, r); //现在，要把这个数的lazy值拿出来用了
	if(x <= mid) update_add(id * 2, l, mid, x, y, v); //遍历左子树
	if(y > mid) update_add(id * 2 + 1, mid + 1, r, x, y, v); //遍历右子树
	pushup(id); //更新区间和
}

int query_sum(int id, int l, int r, int x, int y) { //这个就是简单的线段树查找了，没啥难度------吧！ 
	if(x <= l && r <= y) return sumv[id]; //如果当前区间已经被待更新区间包含了，说明找到了
	int mid = (l + r) >> 1, ans = 0;
	pushdown(id, l, r); //现在，要把这个数的lazy值拿出来用了
	if(x <= mid) ans = (ans + query_sum(id * 2, l, mid, x, y)) % p; //遍历左子树
	if(y > mid) ans = (ans + query_sum(id * 2 + 1, mid + 1, r, x, y)) % p; //遍历右子树
	return ans; //返回找到的区间和
}

signed main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n); //初始化
	while(m--) {
		int d, x, y, k;
		cin >> d >> x >> y;
		if(d == 1) {
			cin >> k;
			update_mul(1, 1, n, x, y, k); 
		} else if(d == 2) {
			cin >> k;
			update_add(1, 1, n, x, y, k);
		} else cout << query_sum(1, 1, n, x, y) << endl;
	}
	return 0;
}
