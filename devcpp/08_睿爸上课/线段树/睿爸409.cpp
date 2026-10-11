#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, a[maxn], sumv[4 * maxn], minv[4 * maxn], maxv[4 * maxn]; //树这种数据结果一般空间都要开到4倍 
void build(int id, int l, int r) { //id表示节点编号，l和r表示区间 
	if(l == r) { //搜到底了
		sumv[id] = minv[id] = maxv[id] = a[l]; //进行赋值 
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid); //遍历左子树 
	build(id * 2 + 1, mid + 1, r); //遍历右子树 
	sumv[id] = sumv[id * 2] + sumv[id * 2 + 1]; //更新和 
	minv[id] = min(minv[id * 2], minv[id * 2 + 1]); //更新最小值 
	maxv[id] = max(maxv[id * 2], maxv[id * 2 + 1]); //更新最大值 
}

//id表示节点编
//l和r表示当前区间
//x和y表示待查找区间 
int query_min(int id, int l, int r, int x, int y) {
	if(x <= l && r <= y) return minv[id]; //找到了 
	int mid = (l + r) / 2, ans = 0x3f3f3f3f; //答案 
	if(x <= mid) ans = min(ans, query_min(id * 2, l, mid, x, y)); //去左子树找最小值 
	if(y >= mid + 1) ans = min(ans, query_min(id * 2 + 1, mid + 1, r, x, y)); //去右子树找最小值 
	return ans;
}

//id表示节点编
//l和r表示当前区间
//x和v表示把第x个元素换位v
void update(int id, int l, int r, int x, int v) {
	if(l == r) { //找到了 
		sumv[id] = minv[id] = maxv[id] = v; //更新 
		return;
	}
	int mid = (l + r) / 2;
	if(x <= mid) update(id * 2, l, mid, x, v); //如果这个点在左边 
	if(x > mid) update(id * 2 + 1, mid + 1, r, x, v); //否则在右边 
	sumv[id] = sumv[id * 2] + sumv[id * 2 + 1]; //一系列的更新 
	minv[id] = min(minv[id * 2], minv[id * 2 + 1]);
	maxv[id] = max(maxv[id * 2], maxv[id * 2 + 1]);
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n); //初始化 
	while(m--) {
		int d, x, y;
		cin >> d >> x >> y;
		if(d == 1) cout << query_min(1, 1, n, x, y) << " ";
		else if(d == 2) update(1, 1, n, x, y);
	}
	return 0;
}
