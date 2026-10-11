#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f  // 表示无穷大
using namespace std;

int n, m, Q, dis[1010][1010];
signed main() {
    cin >> n >> m;
    // 初始化距离矩阵
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = INF;  // 默认无穷大
    // 自己到自己的距离为0
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    // 读取边的信息
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 处理可能存在的多条边情况
        dis[u][v] = dis[v][u] = min(dis[u][v], w);
    }
    // 执行Floyd算法
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] < INF && dis[k][j] < INF)  // 避免溢出
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    cin >> Q;
    while (Q--) {
        int u, v;
        cin >> u >> v;
        if (dis[u][v] != INF) cout << dis[u][v] << endl;
        else cout << -1 << endl;
    }
    return 0;
}
