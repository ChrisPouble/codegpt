#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>

using ll = long long;

const int N = 2505;
 
vector<int> linker[N];
ll w[N]; bool ok[N][N]; // u, v 是否可达
vector <int> can[N]; // f[u] 存放：可达 u 且可达 1 的前三大 v
 
int n, m, k, dis[N];
 
void work_bfs(int x) {
    memset(dis, -1, sizeof(dis));

    queue<int> q;
    q.push(x), dis[x] = 0;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        if (u != x) {
            ok[x][u] = true;
            if (x != 1 && ok[1][u]) {
                can[x].push_back(u);
                sort(can[x].begin(), can[x].end(), [](int u, int v) { return w[u] > w[v]; });

                if (can[x].size() > 3) can[x].pop_back();
            }
        }
 
        if (dis[u] >= k + 1)
            continue;
 
        for (int v : linker[u]) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1, q.push(v);
        }
    }
}
 
signed main() {
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++)
        cin >> w[i];
    
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        linker[u].push_back(v);
        linker[v].push_back(u);
    }
 
    for (int u = 1; u <= n; u++)
        work_bfs(u);
 
    ll ans = 0;
    for (int b = 2; b <= n; b++) {
        for (int c = 2; c <= n; c++) {
            if (!ok[b][c]) continue;
            for (int a : can[b]) {
                for (int d : can[c]) {
                    if (a != c && b != d && a != d)
                    // 其他不等关系天然满足了，只有这三组需要检验；
                    // 天然满足的不等关系：a != b，b != c，c != d，请读者自己思考为什么。
                    ans = max(ans, w[a] + w[b] + w[c] + w[d]);
                }
            }
        }
    }
 
    cout << ans << endl;
    return 0;
}