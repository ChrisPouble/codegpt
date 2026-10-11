#include <bits/stdc++.h>
using namespace std;

const int N = 15, M = 1 << N, K = 1010;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int ne[M];
int f[M][K];

void init() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < n; i++)
        g[i][i] = 0;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        a--, b--;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    for (int st = 1; st < 1 << n; ++ st) // 预处理所有状态能够扩展一层后得到的最大的下一层状态
        for (int i = 0; i < n; ++ i)
            if (st >> i & 1)
                for (int j = 0; j < n; ++ j)
                    if (g[i][j] != INF)
                        ne[st] |= 1 << j;
}

int get_cost(int cur, int pre) {
    if ((ne[pre] & cur) != cur) return -1;//如果pre延伸不到cur直接剪枝
    int remain = pre ^ cur;//待更新的方案
    int cost = 0;//记录边权总和
    for (int i = 0; i < n; ++ i)
    {
        if (remain >> i & 1)
        {
            int t = INF;//找出当前连通块内能把该点加入所用的最小边的边长
            for (int j = 0; j < n; ++ j)
                if (pre >> j & 1)
                    t = min(t, g[j][i]);
            cost += t;
        }
    }
    return cost;//返回该次扩展的费用
}

int dp() {
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < n; ++ i) f[1 << i][0] = 0; // 开局免费选一个起点（初始状态）
    for (int cur = 1, cost; cur < 1 << n; ++ cur)
        for (int pre = cur - 1 & cur; pre; pre = pre - 1 & cur)
            if (~(cost = get_cost(cur, pre)))
                for (int k = 1; k < n; ++ k)
                    f[cur][k] = min(f[cur][k], f[pre][k - 1] + cost * k);
    int res = INF;
    for (int k = 0; k < n; ++ k) res = min(res, f[(1 << n) - 1][k]);//目标状态中找最优解
    return res;
}

int main() {
    init();
    cout << dp() << endl;
    return 0;
}