#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

struct edge {
    int to, w;
};

int n, m, ans, dis[maxn];
bool vis[maxn]; //判断是否在点集合里
vector<edge>linker[maxn];
void add(int x, int y, int w) {
    linker[x].push_back({y, w});
    linker[y].push_back({x, w});
}

void prim(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    for (int i = 1; i < n; i++) {
        int x = n + 1;
        for (int j = 1; j <= n; j++)
            if(!vis[j] && dis[j] < dis[x]) x = j;
        if(dis[x] == dis[n + 1]) {
            cout << "impossible" << endl;
            exit(0);
        }
        vis[x] = 1;
        for (auto k:linker[x]) {
            int v = k.to, w = k.w;
            if(!vis[v]) dis[v] = min(dis[v], w); //已经在点集合里的点不能更新
        }
    }

}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w, add(x, y, w);
    }
    prim(1);
    for (int i = 1; i <= n; i++) ans += dis[i];
    cout << ans << endl;
    return 0;
}
