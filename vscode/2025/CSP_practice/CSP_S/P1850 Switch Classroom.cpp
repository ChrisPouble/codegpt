#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e3 + 10;
const int M = 310;

int n, m, V, E;
int a[N], b[N];
int dis[M][M];

double p[N];
double f[N][N][2]; // f[i][j][0 / 1] 表示前 i 个时间段中，更换教室的次数为 j，且当前更换 / 不更换教师可以获得的最大期望值

signed main() {
    cin >> n >> m >> V >> E;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> p[i];

    memset(dis, 0x3f, sizeof(dis));

    for (int i = 1; i <= V; i++)
        dis[i][i] = 0;

    for (int i = 1; i <= E; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        dis[x][y] = dis[y][x] = min(dis[x][y], w);
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= 1; k++)
                f[i][j][k] = 1e9;

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    f[1][0][0] = f[1][1][1] = 0; // 初始化

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j][0] = min(f[i - 1][j][0] + dis[a[i - 1]][a[i]], 
                             f[i - 1][j][1] + dis[a[i - 1]][a[i]] * (1 - p[i - 1]) + dis[b[i - 1]][a[i]] * p[i - 1]);
            if (!j) continue;
            f[i][j][1] = min(f[i - 1][j - 1][0] + dis[a[i - 1]][a[i]] * (1 - p[i]) + dis[a[i - 1]][b[i]] * p[i], 
                             f[i - 1][j - 1][1] + dis[a[i - 1]][a[i]] * (1 - p[i - 1]) * (1 - p[i])
                                                + dis[a[i - 1]][b[i]] * (1 - p[i - 1]) * p[i]
                                                + dis[b[i - 1]][a[i]] * p[i - 1] * (1 - p[i])
                                                + dis[b[i - 1]][b[i]] * p[i - 1] * p[i]);
        }
    }

    double ans = 1e9;
    for (int i = 0; i <= m; i++)
        ans = min(ans, min(f[n][i][0], f[n][i][1]));

    printf("%.2lf\n", ans);

    system("pause");
    return 0;
}