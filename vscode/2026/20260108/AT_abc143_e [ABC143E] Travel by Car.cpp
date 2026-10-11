#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn = 0x3f3f3f3f;
int n, m, l, Q, ans, dis[310][310];
signed main() {
	cin >> n >> m >> l;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = dis[v][u] = w; //双向边 
	}
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0; //相同的点需要走的路程一样 
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); //floyed
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(i == j) dis[i][j] = 0; //如果点相同，则不需要加油 
			else if(dis[i][j] <= l) dis[i][j] = 1; //如果走的路程小于油箱的容量，则只要加一次油 
			else dis[i][j] = maxn; //此时把油箱加满了也不能接着走 
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]); //再跑一遍 
	cin >> Q;
	while(Q--) {
		int s, t;
		cin >> s >> t;
		if(dis[s][t] != maxn) cout << dis[s][t] - 1 << endl;
		else cout << -1 << endl;
	}
    return 0;
}