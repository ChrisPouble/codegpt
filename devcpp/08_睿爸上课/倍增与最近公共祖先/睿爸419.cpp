#include <bits/stdc++.h>
#define maxn 200010 //请注意，不要觉得开到100010(开到100010有一个点会RE)就可以了，考虑的多一点更好(反正内存给了256MiB) 
#define int long long
using namespace std;

int n, m, q, listans, sum[maxn], father[maxn][30], dep[maxn]; //father[i][j]表示由第i个点往上跳2^j步可以到达的点 
unordered_map<int, unordered_map<int, int> >dis; //邻接表 
vector<int>linker[maxn]; //邻接矩阵
//邻接表和邻接矩阵一起用的原因是因为它俩都有自己的优势 
void dfs(int x) { //求出每个节点的深度 
	if(father[x][0] == -1) dep[x] = 1; //如果没有父节点，则深度为1 
	else dep[x] = dep[father[x][0]] + 1; //否则为自己父节点深度+1 
	for (int i = 0; i < linker[x].size(); i++) { //把这个点所有的点都找一遍 
		int v = linker[x][i];
		if(v != father[x][0]) dfs(v); //接着去更新自己的下一个点 
	}
}

void work(int x) { //求出每个节点到根节点的距离 
	if(father[x][0] == -1) sum[1] = 0; //如果没有父节点，则自己到根节点的距离为0 
	else sum[x] = sum[father[x][0]] + dis[x][father[x][0]]; //否则距离为父节点到根节点的距离+自己到父节点的距离 
	for (int i = 0; i < linker[x].size(); i++) {
		int v = linker[x][i];
		if(v != father[x][0]) work(v); //接着去更新自己的下一个点 
	}
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y); //首先，深度高的要与深度低的并为同一深度 
	int k = 0; //枚举最大能跳多少
	while((1ll << (k + 1)) <= dep[x]) k++; //还能跳就接着跳 
	for (int i = k; i >= 0; i--)
		//由于一个数必定可以由1、2、4、8、16......这些点组成，所以，可以用倍增优化 
		if(dep[father[x][i]] >= dep[y]) x = father[x][i]; //让x和y处于同一高度 
	if(x == y) return x; //特判 
	for (int i = k; i >= 0; i--) //枚举向上跳多少 
		if(father[x][i] != father[y][i]) {
			x = father[x][i]; //我要一步一步往上爬。------ <<蜗牛>> 
			y = father[y][i];
		}
	return father[x][0]; //最后会停留在公共祖先的下一个位置，所以要返回father[x][i]
}

signed main() {
	cin >> n >> m;
	memset(father, -1, sizeof(father)); 
	for (int i = 1; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if(father[a][0] == -1 && father[b][0] == -1 && b < a) swap(a, b); //如果两个节点都没有父节点，并且b < a(我们要求小的在上面，比如我们经常以1做根节点)，就交换 
		else if(father[b][0] != -1) swap(a, b); //如果b有父节点，交换(但我似乎也不知道为啥要交换)
		father[b][0] = a; //记录父节点 
		dis[a][b] = dis[b][a] = c; //邻接矩阵记录边权 
		linker[a].push_back(b); //邻接表记录终点 
		linker[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		if(father[i][0] == -1) { //如果这个点是根节点 
			dfs(i); //记深度
			work(i); //记前缀和 
			break;
		}
	for (int j = 1; (1ll << j) <= n; j++) //枚举向上跳几步 
		for (int i = 1; i <= n; i++) //找出所有的点 
			father[i][j] = father[father[i][j - 1]][j - 1]; //先跳2^(j-1)步，再跳2^(j-1)步就可以了 
	cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		int x = (listans + a) % n + 1;
		int y = (listans + b) % n + 1;
		listans = sum[x] + sum[y] - 2 * sum[LCA(x, y)];
		cout << listans << endl;
	}
    return 0;
}
