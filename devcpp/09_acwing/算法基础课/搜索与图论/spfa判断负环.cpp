#include <bits/stdc++.h>
#define maxn 150010
using namespace std;

struct edge {
    int to, w; //去向和边权
};

int n, m, dis[maxn], cnt[maxn]; //cnt表示边数
bool vis[maxn]; //是否在队列里 
queue<int>que;
vector<edge>linker[maxn];
void add(int x, int y, int w) {
    linker[x].push_back({y, w});
}

void SPFA() {
    vis[0] = 1, que.push(1);
    while(!que.empty()) {
        int x = que.front();
        que.pop();
        vis[x] = 0; //清除存在记录 
        for (auto k:linker[x]) {
            int v = k.to, w = k.w;
            if(dis[v] > dis[x] + w) { //松弛 
                dis[v] = dis[x] + w; //距离更新
                cnt[v] = cnt[x] + 1; //边数更新 
                if(cnt[x] > n) { //经过了n条边，n+1个点（不能算上虚拟节点） 
                    cout << "Yes" << endl;
                    exit(0);
                }
                if(!vis[v]) que.push(v); //放入队列 
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y, w; i <= m; i++) cin >> x >> y >> w, add(x, y, w);
    for (int i = 1; i <= n; i++) linker[0].push_back({i, 0});
    SPFA();
    cout << "No" << endl;
    return 0;
}
