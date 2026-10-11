#include <bits/stdc++.h>
using namespace std;

int n, m, fa[310]; //最小生成树需要用到并查集 
struct node{
	int u, v, w;
}a[100010];

int find(int x) { //查找 
	if(x == fa[x]) return x;
	else {
		fa[x] = find(fa[x]);
		return fa[x];
	}
}

void hb(int x, int y) { //合并 
	int tx = find(x);
	int ty = find(y);
	if(tx != ty) fa[tx] = ty;
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

int ds() {
	sort(a + 1, a + 1 + m, cmp); //给边权从小到大排序 
	int max_sum = 0; //最大边 
	int txt = 0; //记录已经选了多少条边 
	for (int i = 1; i <= m; i++) {
		if(txt == n - 1) return max_sum; //最小生成树的边数是n - 1，所以边数达到n - 1就返回 
		if(find(a[i].u) != find(a[i].v)) { //两点是否以连通 
			hb(a[i].u, a[i].v); //不连通就合并 
			max_sum = max(max_sum, a[i].w); //找出最大边 
			txt++; //边数增加 
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	for (int i = 1; i <= n; i++) //初始化 
		fa[i] = i;
	cout << n - 1 << " " << ds() << endl;
	return 0;
}
