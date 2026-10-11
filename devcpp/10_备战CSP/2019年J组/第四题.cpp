#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, q, dis[maxn][2]; //dis[i][0/1]表示从1点到i点的最短距离，0表示距离为偶数，1表示距离为奇数 
queue<int>que;
vector<int>linker[maxn]; //邻接表 
int main() {
	memset(dis, 0x3f, sizeof(dis)); //初始化 
	cin >> n >> m >> q;
	while(m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		linker[u].push_back(v), linker[v].push_back(u); //邻接表加入无向图 
	}
	dis[1][0] = 0, que.push(1); //初始化 
	while(!que.empty()) {
		int x = que.front();
		que.pop();
		for (auto y:linker[x]) { //枚举与x相连的y 
			int x1 = dis[y][0], y1 = dis[y][1]; //记录在更新之前的dis[y] 
			dis[y][0] = min(dis[y][0], dis[x][1] + 1); //更新 
			dis[y][1] = min(dis[y][1], dis[x][0] + 1); //更新 
			if(dis[y][0] < x1 || dis[y][1] < y1) que.push(y); //如果值变得更小，则加入队列 
		}
	}
	while(q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		if(dis[u][0] <= v && v % 2 == 0 && linker[u].size()) printf("Yes\n"); //L为偶数的情况
		else if(dis[u][1] <= v && v % 2 == 1 && linker[u].size()) printf("Yes\n"); //L为奇数的情况 
		else printf("No\n"); //否则输出No 
	}
	return 0;
}
