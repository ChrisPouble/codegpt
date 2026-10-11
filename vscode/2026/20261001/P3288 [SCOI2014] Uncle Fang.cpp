#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
const double eps = 1e-6;

int n, m;

struct Edge { int to, w, nxt; };
int tot, head[N]; Edge e[N << 1];

void add(int u, int to, int w) {
    e[++tot] = { to, w, head[u] };
    head[u] = tot;
}

bool vis[N];
double dis[N];
int cnt[N]; // 当前松弛路径的边数

bool check(int u, double trp) {
    queue <int> que;
    vis[u] = 1; que.push(u);

    while (!que.empty()) {
        int h = que.front(); que.pop();
        vis[h] = 0;

        for (int now = head[h]; now; now = e[now].nxt) {
            int v = e[now].to;

            // 从 h 沿边松弛 v，边权需要加上二分值 trp
            if (dis[v] > dis[h] + e[now].w + trp) {
                dis[v] = dis[h] + e[now].w + trp;
                cnt[v] = cnt[h] + 1;

                if (cnt[v] >= n)
                    return 1;

                if (!vis[v]) {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }

    return 0;
}

bool whether(double trp) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));

    // 从每个点尝试，避免漏掉其他连通块中的负环
    for (int i = 1; i <= n; i++) {
        if (check(i, trp)) 
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    n += 2;

    for (int i = 1; i <= m; i++) {
        int u, v, a, b, c, d;
        cin >> u >> v >> a >> b >> c >> d;

        if (c) add(v, u, a - d); // 压缩：反向退流
        add(u, v, b + d);        // 扩容：正向增广
    }

    double l = 0, r = 1e9, ans = 0;

    while (r - l > eps) {
        double mid = (l + r) / 2;

        if (whether(mid)) {
            // 有负环，说明答案比 mid 大
            l = mid, ans = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(2) << ans << "\n";

    return 0;
}