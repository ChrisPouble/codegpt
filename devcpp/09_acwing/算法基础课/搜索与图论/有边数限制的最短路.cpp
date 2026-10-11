#include <bits/stdc++.h>
#define maxn 10010
using namespace std;

struct Edge {
    int a, b, w;
} edge[maxn];

int n, m, k, dis[maxn], backup[maxn];
void Bellman_Ford(int st) {
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) backup[j] = dis[j];
        for (int j = 1; j <= m; j++) {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }
}

signed main() {
    cin >> n >> m >> k;
    for (int i = 1, x, y, w; i <= m; i++) cin >> x >> y >> w, edge[i] = {x, y, w};
    Bellman_Ford(1);
    if(dis[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else cout << dis[n] << endl;
    return 0;
}
