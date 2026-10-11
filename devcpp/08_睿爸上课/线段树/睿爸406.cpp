#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

int n, m, cnt, a[maxn], tree[maxn], DFN[maxn], siz[maxn];
//a[i]表示第i个节点上有没有苹果，tree[i]表示前i个数的和，DFN[i]表示第i个数的编号，siz[i]表示第i个节点有多少个子节点 
vector<int>linker[maxn]; //邻接表存储子节点 
int dfs(int id) {
	DFN[id] = ++cnt; //记录编号 
	siz[id] = 1; //子节点也包括自己 
	for (auto i:linker[id])
		siz[id] += dfs(i); //计算子节点的数量 
	return siz[id];
}

int lowbit(int x) {
	return x & (-x);
}

void update(int x, int v) { //修改节点信息 
	while(x <= n) {
		tree[x] += v;
		x += lowbit(x);
	}
}

int query(int x) { //查找节点信息 
	int ans = 0;
	while(x) {
		ans += tree[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		linker[u].push_back(v); //记录子节点 
	}
	dfs(1); //初始化 
	for (int i = 1; i <= n; i++)
		a[i] = 1, update(i, 1); //初始化 
	while(m--) {
		char op[5];
		int x;
		scanf("%s%d", op, &x);
		if(op[0] == 'C') {
			if(a[x] == 0) a[x] = 1, update(DFN[x], 1); //如果没有苹果，则长出一个苹果，并且更新节点信息 
			else a[x] = 0, update(DFN[x], -1); //如果已有苹果，则摘掉一个苹果，并且更新节点信息 
		} else {
			int l = DFN[x]; //左边界
			int r = DFN[x] + siz[x] - 1; //右边界
			printf("%d\n", query(r) - query(l - 1)); //区间和 
		}
	}
	return 0;
}
