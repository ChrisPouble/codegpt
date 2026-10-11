#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int n, m, dis[maxn]; //dis[i]表示起点到达编号为i的点需要的时间 
bool vis[maxn]; //vis[i]表示这个点有没有遍历过 
struct node {
	int id, value; //一个点的编号和起点到达这个点的最短路径 
};

struct rate { //存一条边 
	int to, w; //存储一个点可以到达的点和到达这个点需要的时间 
};

bool operator<(node A, node B) { //堆排序 
	return A.value > B.value; //找到离起点时间最小的点来更新别的点 
}

vector<rate>linker[maxn]; //邻接表 
priority_queue<node>q; //堆优化 
signed main() {
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		linker[u].push_back({v, w}); //存下一条边 
	}
	for (int i = 1; i <= n; i++)
		dis[i] = 1e10; //赋上一个很大的值 
	dis[s] = 0ll; //初始化 
	q.push({s, 0ll}); //把起点塞进去 
	while(!q.empty()) {
		node temp = q.top();
		q.pop();
		if(vis[temp.id]) continue; //如果已经遍历过了，就continue 
		int id = temp.id; //取出编号 
		int val = temp.value; //取出从起点到达这个点需要的时间 
		vis[id] = 1; //这个点被访问过了 
		dis[id] = min(val, dis[id]); //更新值 
		for (int i = 0; i < linker[id].size(); i++)
			q.push({linker[id][i].to, val + linker[id][i].w}); //把所有能达到的点都加进去 
	}
	for (int i = 1; i <= n; i++)
		if(dis[i] == 1e10) cout << -1 << " ";
		else cout << dis[i] << " ";
	return 0;
}
