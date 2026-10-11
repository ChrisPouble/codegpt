#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

const int A = 360000, B = 1210000, C = 2200, D = 55, INF = 1000000000;

struct Edge {
    int to, nt, ct;
} e[B];

struct Question {
    int x3, p, t;
} q[D];

int n, m, T, tl;
int to[A][2], hd[A], dis[A];
int w[D][D], gt[D], f[D][D];
int is[C], id[C], cf[C];

using Pii = pair<int, int>;
priority_queue<Pii, vector<Pii>, greater<Pii>> ccf;

void AddEdge(int u, int v, int w) {
    e[tl].to = v;
    e[tl].ct = w;
    e[tl].nt = hd[u];
    hd[u] = tl++;
}

bool CmpQuestion(const Question &a, const Question &b) {
    return a.p < b.p;
}

void Dijkstra(int s, int U) {
    for (int i = 0; i < U; ++i) {
        dis[i] = INF;
    }
    ccf.emplace(dis[s] = 0, s);
    while (!ccf.empty()) {
        Pii now = ccf.top(); ccf.pop();
        int u = now.second;
        for (int z = hd[u]; ~z; z = e[z].nt) {
            int v = e[z].to;
            if (dis[u] + e[z].ct < dis[v]) {
                dis[v] = dis[u] + e[z].ct;
                ccf.emplace(dis[v], v);
            }
        }
        while (!ccf.empty() && dis[ccf.top().second] < ccf.top().first) {
            ccf.pop();
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0, ti = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j, ++ti) {
            scanf("%d", &to[ti][0]);
        }
    }
    for (int i = 0, ti = 0; i < n; ++i, ++ti) {
        for (int j = 0; j + 1 < m; ++j, ++ti) {
            scanf("%d", &to[ti][1]);
        }
    }
    for (int i = 0; i + 1 < m; ++i) {
        id[i] = to[i][1];
        cf[i] = i;
    }
    for (int i = 0; i + 1 < n; ++i) {
        id[m + i] = to[i * m + m - 1][0];
        cf[m + i] = i * (m - 1) + m - 2;
    }
    for (int i = 0; i + 1 < m; ++i) {
        id[m + n + i] = to[(n - 1) * m + m - 2 - i][1];
        cf[m + n + i] = (n - 2) * (m - 1) + m - 2 - i;
    }
    for (int i = 0; i + 1 < n; ++i) {
        id[m + m + n + i] = to[(n - 2 - i) * m][0];
        cf[m + m + n + i] = (n - 2 - i) * (m - 1);
    }
    id[m - 1] = id[m + n - 1] = id[m + m + n - 1] = id[m + m + n + n - 1] = -1;

    while (T--) {
        int k;
        scanf("%d", &k);
        tl = 0;
        for (int i = (m - 1) * (n - 1) + k - 1; i >= 0; --i) {
            hd[i] = -1;
        }
        for (int i = 0, ti = 1, tj = 0; i + 1 < n; ++i, ti += 2, ++tj) {
            for (int j = 1; j + 1 < m; ++j, ++ti, ++tj) {
                AddEdge(tj, tj + 1, to[ti][0]);
                AddEdge(tj + 1, tj, to[ti][0]);
            }
        }
        for (int i = 1, ti = m, tj = 0; i + 1 < n; ++i, ++ti) {
            for (int j = 0; j + 1 < m; ++j, ++ti, ++tj) {
                AddEdge(tj, tj + m - 1, to[ti][1]);
                AddEdge(tj + m - 1, tj, to[ti][1]);
            }
        }
        for (int i = 0; i < k; ++i) {
            scanf("%d%d%d", &q[i].x3, &q[i].p, &q[i].t);
            --q[i].p;
        }
        sort(q, q + k, CmpQuestion);
        q[k] = q[0];
        int u = (m - 1) * (n - 1), gi = 0;
        AddEdge(u, u + k - 1, q[0].x3);
        AddEdge(u + k - 1, u, q[0].x3);
        for (int i = 0; i < k; ++i, ++u) {
            if (i) {
                AddEdge(u, u - 1, q[i].x3);
            }
            if (i + 1 < k) {
                AddEdge(u, u + 1, q[i + 1].x3);
            }
            for (int j = q[i].p; j != q[i + 1].p; j = (j + 1 == m + m + n + n ? 0 : j + 1)) {
                if (id[j] >= 0) {
                    AddEdge(u, cf[j], id[j]);
                    AddEdge(cf[j], u, id[j]);
                }
            }
            if (q[i].t != q[i + 1].t) {
                gt[gi++] = u;
            }
        }
        for (int i = 0; i < gi; ++i) {
            Dijkstra(gt[i], u);
            for (int j = 0; j < gi; ++j) {
                w[i][j] = dis[gt[j]];
                f[i][j] = INF;
            }
            if (i + 1 < gi) {
                f[i][i + 1] = w[i][i + 1];
            }
        }
        for (int len = 3; len < gi; len += 2) {
            for (int l = 0; l + len < gi; ++l) {
                int r = l + len;
                f[l][r] = min(f[l][r], f[l + 1][r - 1] + w[l][r]);
                for (int mid = 1; mid < len; mid += 2) {
                    f[l][r] = min(f[l][r], f[l][l + mid] + f[l + mid + 1][r]);
                }
            }
        }
        printf("%d\n", f[0][gi - 1]);
    }
    return 0;
}