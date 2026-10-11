#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;

const int N = 1e5 + 10;
const int M = 4e5 + 10;
const int S = 60;

int n, m, k, P;
int dis[N], vis[N];
int f[N][S];
bool pdv[N][S];

vector<PII> linker[N], linkai[N];
priority_queue<PII, vector<PII>, greater<PII> > q;

void add(int x, int y, int w) {
    linker[x].push_back({ y, w });
    linkai[y].push_back({ x, w });
}

void Dijkstra() {
    dis[1] = 0;
    q.push({ 0, 1 });

    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();

        if (vis[u]) continue;
        vis[u] = 1;

        for (auto k : linker[u]) {
            int v = k.first, w = k.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({ dis[v], v });
            }
        }
    }
}

bool flag;
int dfs(int u, int k) {
    if (k < 0) return 0;
    if (k > 50) return 0;
    if (pdv[u][k]) { flag = 1; return 0; }
    if (~f[u][k]) return f[u][k];

    pdv[u][k] = 1;
    int ans = 0;
    for (auto i : linkai[u]) {
    	int v = i.first, w = i.second;  
    	ans += dfs(v, dis[u] - dis[v] + k - w);
        ans %= P;
    }

    pdv[u][k] = 0;
    return f[u][k] = ans;
}

void solve() {
    for (int i = 1; i <= n; i++) {
        linker[i].clear();
        linkai[i].clear();
    }

    cin >> n >> m >> k >> P;

    memset(dis, 0x3f, sizeof(dis));
    memset(f, -1, sizeof(f));
    memset(vis, 0, sizeof(vis));
    memset(pdv, 0, sizeof(pdv));

    flag = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        add(u, v, w);
    }

    Dijkstra();
    f[1][0] = 1;

    if (k == 0) {
        dfs(n, 1);
        if (flag) {
            cout << -1 << "\n";
            return ;
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++)
        ans = (ans + dfs(n, i)) % P;
    
    if (flag) ans = -1;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}