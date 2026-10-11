#include <bits/stdc++.h>
#define maxn 210
#define INF 1000000000
using namespace std;

int n, m, k, x, y, dis[maxn][maxn];
void Floyed() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
            if(i == j) dis[i][j] = 0;
            else dis[i][j] = INF;
    for (int i = 1, w; i <= m; i++) cin >> x >> y >> w, dis[x][y] = min(dis[x][y], w);
    Floyed();
    while(k--) {
        cin >> x >> y;
        if(dis[x][y] > INF / 2) cout << "impossible" << endl;
        else cout << dis[x][y] << endl;
    }
    return 0;
}
