#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 易错点 1：这里不能写 1e4 + 10，要写 1e4 + 15，因为我们会访问到 n + k
const int N = 1e4 + 15;
const int M = 1e6 + 15;

int n, m, k, fa[N];
int cost[15], vis[15];

struct node {
    int u, v, w;
} edge[M], oos[M];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    // 易错点 2：初始化并查集要遍历到 n + k
    for (int i = 1; i <= n + k; i++)
        fa[i] = i;

    for (int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        edge[i] = { u, v, w };
    }

    sort(edge + 1, edge + 1 + m, cmp);

    int tot = 0;
    for (int i = 1; i <= m; i++) {
        int fu = find(edge[i].u);
        int fv = find(edge[i].v);
        if (fu != fv) {
            fa[fv] = fu;
            oos[++tot] = edge[i];
            if (tot == n - 1) break;
        }
    }

    for (int i = 1; i <= k; i++) {
        cin >> cost[i];
        for (int j = 1, w; j <= n; j++) {
            cin >> w;
            oos[++tot] = { j, n + i, w };
        }
    }

    sort(oos + 1, oos + 1 + tot, cmp);

    ll ans = 1e18;

    for (int stat = 0; stat < (1 << k); stat++) {
        // 易错点 3：这里变量名不能混淆
        int num = 0;
        ll now = 0;

        // 枚举选边
        for (int i = 0; i < k; i++) { // 这里遍历用了 0 ~ k - 1
            if ((stat >> i) & 1) {
                vis[i + 1] = 1; // 易错点 4：因此这里要 + 1
                num++, now += cost[i + 1];
            } else vis[i + 1] = 0;
        }

        // 跑最小生成树
        for (int i = 1; i <= n + k; i++)
            fa[i] = i;

        int need = n + num - 1;

        for (int i = 1; i <= tot; i++) {
            int u = oos[i].u;
            int v = oos[i].v;

            // 易错点 5：没有选到的结点不考虑
            if (u > n && !vis[u - n]) continue;
            if (v > n && !vis[v - n]) continue;

            int fu = find(u);
            int fv = find(v);
            if (fu != fv) {
                fa[fv] = fu, need--;
                now += oos[i].w;
                if (!need) break;
            }
        }

        if (!need) ans = min(ans, now);
    }

    cout << ans << "\n";
    return 0;
}