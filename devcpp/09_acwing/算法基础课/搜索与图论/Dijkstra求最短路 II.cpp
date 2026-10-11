#include <bits/stdc++.h>
#define maxn 150010
using namespace std;

struct edge { //存边的信息 
    int to, w; //去向和边权
};

struct node { //存点的信息 
    int dis, x; //dis值和节点
};

int n, m, dis[maxn];
bool vis[maxn];
priority_queue<node>que; //堆 
vector<edge>linker[maxn];
void add(int x, int y, int w) {
    linker[x].push_back({y, w});
}

bool operator<(node x, node y) { //堆优化，启动！ 
    return x.dis > y.dis;
}

void dijkstra(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0, que.push({0, st});
    while(!que.empty()) {
        int x = que.top().x;
        que.pop();
        if(vis[x]) continue; //如果已经更新过了，就没有更新的必要 
        vis[x] = 1; //标记
        for (auto k:linker[x]) {
            int v = k.to, w = k.w;
            if(dis[v] > dis[x] + w) {
                dis[v] = dis[x] + w;
                que.push({dis[v], v}); //更新 
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
    cout << (dis[n] == 0x3f3f3f3f ? -1 : dis[n]) << endl;
    return 0;
}
