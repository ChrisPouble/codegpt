#include <bits/stdc++.h>
#define int long long //不开long long见祖宗 
using namespace std;

int n, m, ans, a[200010], fa[200010];
struct edge {
	int u, v, w; //一条边的起点、终点、权值 
};

vector<edge>linker; //存储每一条边 
bool cmp(edge x, edge y) { //权值小的边先考虑 
	return x.w < y.w;
}

int find(int x) {
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]); //路径压缩 
}

void merge(int x, int y) { //合并两个点 
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

void tree() { //最小生成树 
	for (auto i:linker) //遍历所有的边 
		if(find(i.u) != find(i.v)) { //如果这两个边已经连上了，则不考虑 
			merge(i.u, i.v); //否则进行合并 
			ans += i.w; //花费加上w 
		}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = i; //并查集千万别忘了打初始化 
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		minp = a[i] < a[minp] ? i : minp; //找到最小的那条边 
	for (int i = 1; i <= n; i++)
		linker.push_back({i, minp, a[i] + a[minp]}); //把这条边与其它的边连起来 
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		linker.push_back({u, v, w});
	}
	sort(linker.begin(), linker.end(), cmp); //进行排序 
	tree();
	cout << ans << endl;
	return 0;
}
