#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

struct edge {
    int to, w;
};

int n, m, dis[maxn];
bool vis[maxn];
vector<edge>linker[maxn]; //邻接表 
void add(int x, int y, int w) {
    linker[x].push_back({y, w}); //邻接表建边 
}

void dijkstra(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    for (int i = 1; i <= n; i++) {
        int x = n + 1;
        for (int j = 1; j <= n; j++)
            if(!vis[j] && dis[j] < dis[x]) x = j; //找出可以用来更新，且离起点最短的点 
        vis[x] = 1; //以后不能更新了
        for (auto k:linker[x]) {
            int v = k.to, w = k.w;
            dis[v] = min(dis[v], dis[x] + w); //更新 
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w, add(x, y, w);
    }
    dijkstra(1);
    cout << (dis[n] == 0x3f3f3f3f ? -1 : dis[n]) << endl;
    return 0;
}
