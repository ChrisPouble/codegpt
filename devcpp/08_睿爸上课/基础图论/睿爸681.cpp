#include <bits/stdc++.h>
using namespace std;

int n, m, ans, dis[1010], g[1010][1010];
bool vis[1010];
void prim() {
	memset(dis, 0x3f3f3f3f, sizeof(dis)); //初始化 
	dis[1] = 0; //初始化 
	vis[1] = 1; //第一个点访问过了 
	for (int i = 1; i <= n; i++) dis[i] = min(dis[i], g[1][i]); //点1去更新其它的点 
	for (int i = 2; i <= n; i++) {
		int temp = INT_MAX, t = -1; //temp表示最小的dis值，t表示下标 
		for (int j = 1; j <= n; j++)
			if(!vis[j] && temp > dis[j]) {
				temp = dis[j];
				t = j;
			}
		if(t == -1) { //如果下标为-1，说明不能找到边来构成生成树 
			cout << -1 << endl;
			return;
		}
		vis[t] = 1; //进行记录
		for (int j = 1; j <= n; j++)
			if(!vis[j] && dis[j] > g[t][j])//用新加入的点更新dis[]
				dis[j] = g[t][j];
	}
	for (int i = 1; i <= n; i++)
		ans += dis[i];
	cout << ans << endl; 
}

int main() {
	cin >> n >> m;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= n; i++)
		g[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	prim();
	return 0;
}
