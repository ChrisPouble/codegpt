#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

struct edge {
    int to, w;
};

struct node { //代表一个点的dis值和id 
	int dis, x;
}; 

int n, m, ans, dis[maxn];
bool vis[maxn]; //判断是否在点集合里
priority_queue<node>q;
vector<edge>linker[maxn];
bool operator<(node x, node y) { //堆优化，启动！ 
	return x.dis > y.dis;
} 

void add(int x, int y, int w) {
    linker[x].push_back({y, w});
    linker[y].push_back({x, w});
}

void prim(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    q.push({0, st});
    while(!q.empty()) {
        int x = q.top().x;
        q.pop();
//        if(vis[x]) continue;
        vis[x] = 1; //标记已经进入点集合了 
        for (auto k:linker[x]) {
            int v = k.to, w = k.w;
            if(!vis[v] && w < dis[v]) dis[v] = w, q.push({w, v}); //已经在点集合里的点不能更新
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w, add(x, y, w);
    }
    prim(1);
    for (int i = 1; i <= n; i++)
		if(dis[i] == 0x3f3f3f3f) { cout << "impossible" << endl; return 0; }
		else ans += dis[i];
	cout << ans << endl;
    return 0;
}
