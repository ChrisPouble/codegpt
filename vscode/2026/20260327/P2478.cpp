#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int M = 2e6 + 10;
const int inf = 0x3f3f3f3f;

int n, m, w[N], bk[N];
int dfn[N], low[N], fa[N];
int f[N][3];

struct Edge {
    int u, v, nxt;
} edge[M * 2];

int head[N];

int top = 1;
void add(int u, int v) {
    edge[++top] = { u, v, head[u] };
    head[u] = top;
}

void merge(int x, int v) {
    f[x][0] += f[v][2];
    f[x][1] += max(f[v][1], f[v][2]);
    f[x][2] += max(f[v][1], f[v][2]);
}

vector<int> collect(int x, int y) {
    vector<int> cyc;

    int p = y;
    while (p != x) {
        cyc.push_back(p);
        p = fa[p];
    }

    reverse(cyc.begin(), cyc.end());

    return cyc;
}

bool check(int pp, int pre, int cur) {
    if (pre == 0 && cur != 2) return false;
    if (pre == 1 && cur == 0) return false;
    if (pp == 0 && cur == 0) return false;
    return true;
}

int cycle(int x, int y) {
    vector<int> cyc = collect(x, bk[x]);
    int len = cyc.size();

    int R0 = -inf, Rclean = -inf, Rsel = -inf;
    for (int s1 = 0; s1 <= 2; s1++) {
        for (int s2 = 0; s2 <= 2; s2++) {
            if (!check(-1, s1, s2)) continue;

            int dp[3][3];
            memset(dp, -0x3f, sizeof dp);
            dp[s1][s2] = f[cyc[0]][s2];
            
            for (int i = 1; i < len; i++) {
                int now = cyc[i];
                int ndp[3][3];
                memset(ndp, -0x3f, sizeof ndp);
                
                for (int a = 0; a <= 2; a++)
                    for (int b = 0; b <= 2; b++)
                        for (int c = 0; c <= 2; c++) {
                            if (dp[a][b] <= -(inf / 2)) continue;
                            if (!check(a, b, c)) continue;
                            ndp[b][c] = max(ndp[b][c], dp[a][b] + f[now][c]);
                        }
                
                memcpy(dp, ndp, sizeof dp);
            }
            
            for (int a = 0; a <= 2; a++)
                for (int b = 0; b <= 2; b++) {
                    if (dp[a][b] <= -(inf / 2)) continue;
                    if (b == 0 && s1 != 2) continue;
                    if (b == 1 && s1 == 0) continue;
                    if (a == 0 && s1 == 0) continue;
                    if (b == 0 && s2 == 0) continue;
                    
                    if (s1 == 0) {
                        R0 = max(R0, dp[a][b]);
                    } else if (s1 == 2) {
                        if (s2 != 0 && b != 0) Rclean = max(Rclean, dp[a][b]);
                        else Rsel = max(Rsel, dp[a][b]);
                    }
                }
        }
    }

    f[x][0] += R0;
    f[x][2] += Rclean;
    f[x][1] += Rclean;
    return Rsel - Rclean;
}

int tim;
void dfs(int x, int fat, int ine) {
    dfn[x] = low[x] = ++tim, fa[x] = fat;
    f[x][0] = w[x], f[x][1] = -inf;

    int best = -inf;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int v = edge[i].v;
        if ((i ^ 1) == ine) continue;

        if (dfn[v] == 0) {
            dfs(v, x, i);
            low[x] = min(low[x], low[v]);
            if (low[v] > dfn[x]) { // 树边（割边）
                merge(x, v);
                best = max(best, f[v][0] - max(f[v][1], f[v][2]));
            } else if (low[v] == dfn[x]) { // 环顶（割点）
                int get = cycle(x, v);
                best = max(best, get);
            } 
        }
        else low[x] = min(low[x], dfn[v]), bk[v] = x;
    }

    f[x][1] = f[x][2] + best; // f[u][1] = f[u][2] + best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        add(x, y), add(y, x);
    }

    dfs(1, 0, 0);

    cout << max(f[1][0], max(f[1][1], f[1][2])) << endl;

    return 0;
}