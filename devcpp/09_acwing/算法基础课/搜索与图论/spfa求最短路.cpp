#include <bits/stdc++.h>
#define maxn 150010
using namespace std;

struct edge {
    int to, w; //去向和边权
};

int n, m, dis[maxn];
bool vis[maxn]; //是否在队列里 
queue<int>que;
vector<edge>linker[maxn];
void add(int x, int y, int w) {
    linker[x].push_back({y, w});
}

void dijkstra(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0, vis[st] = 1, que.push(st);
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 0;
        for (auto k:linker[x]) {
            int v = k.to, w = k.w;
            if(dis[v] > dis[x] + w) {
                dis[v] = dis[x] + w;
                if(!vis[v]) vis[v] = 1, que.push(v);
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w, add(x, y, w);
    }
    dijkstra(1);
    if(dis[n] == dis[0]) cout << "impossible" << endl; //因为Spfa不会遍历所有边，只会遍历相连的，因此只需要"=="就可以了即可 
    else cout << dis[n] << endl;
    return 0;
}
