#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, q, a[maxn], pre[maxn], tree[maxn];
int lowbit(int x) { 
	return x & (-x);
}

void update(int x, int v) {
	int t = x; 
	while(x <= n) {
		if(x - lowbit(x) + 1 <= t) tree[x] = tree[x] - a[t] + v; //进行节点更新 
		x += lowbit(x); //接着查找 
	}
	a[t] = v; 
}

int query_sum(int x) {
	int ans = 0;
	while(x) {
		ans += tree[x]; //加上 
		x -= lowbit(x); //缩小区间 
	}
	return ans;
}

int query_max(int x, int y) {
	int ans = 0;
	while(x <= y) {
		if(y - lowbit(y) + 1 >= x) { //区间左端点大于等于x，说明可以用tree[y] 
			ans = max(ans, tree[y]); //找出最大值 
			y -= lowbit(y); //接着进行查找 
		} else ans = max(ans, a[y--]); //否则只能一个一个的比较 
	}
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i]; //求出前缀和，用来构造树状数组 
	}
	for (int i = 1; i <= n; i++)
		tree[i] = pre[i] - pre[i - lowbit(i)]; //构建树状数组 
	cin >> q;
	while(q--) {
		int d, x, y;
		cin >> d >> x >> y;
		if(d == 1) cout << query_sum(y) - query_sum(x - 1) << endl; //区间和 
		else if(d == 2) cout << query_max(x, y) << endl; //区间最大值 
		else update(x, y); //把坐标为x的点的值赋值为y 
	}
	return 0;
}
