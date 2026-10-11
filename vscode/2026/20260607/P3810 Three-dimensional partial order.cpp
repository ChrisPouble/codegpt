#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int lowbit(int x) {
	return x & -x;
}

const int N = 2e5 + 10;

struct query { 
	/*
		查询：
	 	  1. 编号
		  2. 左端点
		  3. 右端点
		  4. 区间第 k 小
		  5. 无意义 
	*/ 
	
	/*
		修改：
  		  1. 编号
		  2. 修改断点
		  3. 修改的值
		  4. 无意义
		  5. 判断是 插入 / 删除 
	*/ 
	
	int id, x, y, k, v;
} op[N * 2], o1[N * 2], o2[N * 2];

int n, Q, cnt, a[N], ans[N], tree[N];
int isquery[N];

void add(int x, int d) {
	while (x <= n) {
		tree[x] += d;
		x += lowbit(x);
	}
}

int get(int x) {
	int res = 0;
	while (x) {
		res += tree[x];
		x -= lowbit(x);
	}
	return res;
}

// 整体二分模板 
void work(int low, int high, int st, int ed) {
	if (st > ed) return;
	if (low == high) {
		for (int i = st; i <= ed; i++) ans[op[i].id] = low;
		return;
	}
	
	int mid = (low + high) >> 1, n1 = 0, n2 = 0;
	for (int i = st; i <= ed; i++)
		if (!op[i].id) { // 添加操作 
			// 注意这里只在 op[i].y <= mid 时有修改操作，因为这些值都用来给 > mid 的值做贡献 
			if (op[i].y <= mid) add(op[i].x, op[i].v), o1[++n1] = op[i];
			else o2[++n2] = op[i];
		}
		else { // 查询操作 
			int cnt = get(op[i].y) - get(op[i].x - 1);
			if (cnt >= op[i].k) o1[++n1] = op[i];
			else op[i].k -= cnt, o2[++n2] = op[i];
		}
	
	for (int i = 1; i <= n1; i++)
		if (!o1[i].id) add(o1[i].x, -o1[i].v);
	
	// 归还原数组 
	for (int i = 1; i <= n1; i++) op[st + i - 1] = o1[i];
	for (int i = 1; i <= n2; i++) op[ed - n2 + i] = o2[i];
	
	// 递归继续整体二分 
	work(low, mid, st, ed - n2);
	work(mid + 1, high, st + n1, ed);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	cin >> n >> Q; 
	for (int i = 1, h; i <= n; i++) {
		cin >> a[i];
		op[++cnt] = { 0, i, a[i], 0, 1 };
	}
	
	for (int i = 1, l, r, k; i <= Q; i++) {
		string s;
		cin >> s >> l >> r;
		if (s == "Q") cin >> k, op[++cnt] = { i, l, r, k, 0 }, isquery[i] = 1;
		else op[++cnt] = { 0, l, a[l], 0, -1 }, op[++cnt] = { 0, l, a[l] = r, 0, 1 };
	}
	
	work(0, 1e9, 1, cnt); // 整体二分
	for (int i = 1; i <= Q; i++)
		if (isquery[i]) cout << ans[i] << endl; // 输出答案
	return 0;
}