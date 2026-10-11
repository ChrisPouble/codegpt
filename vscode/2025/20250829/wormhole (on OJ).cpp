#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e4 + 10;

int n, a[N], w[N], s[N], m, dis[N];
bool vis[N];
vector<pair<int, int> > linker[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

void add(int x, int y, int w) {
    linker[x].push_back({y, w});
}

int work(int x, int y) {
    if ((!a[x]) && a[y]) return -abs(w[x] - w[y]);
    if (a[x] && (!a[y])) return abs(w[x] - w[y]);
    return 0;
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    memset(dis, 0x3f, sizeof(dis));

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = 1 - a[i];
    for (int i = 1; i <= n; i++) cin >> w[i], w[i + n] = w[i];
    for (int i = 1; i <= n; i++) cin >> s[i], s[i + n] = s[i];

    // 构造分层图
    for (int i = 1; i <= n; i++) {
        add(i, i + n, (a[i] ? s[i] : 0ll));
        add(i + n, i, (a[i + n] ? s[i + n] : 0ll));
    }

    for (int i = 1, x, y, w; i <= m; i++) {
        cin >> x >> y >> w;

        linker[x].push_back({ y + n, max(w + work(x, y), 0ll) });
        linker[x + n].push_back({ y, max(w + work(x + n, y + n), 0ll) });
    }

    dis[1] = 0;

    q.push({ 0, 1 });
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();

        if (vis[x]) continue;
        vis[x] = 1;
        for (auto i : linker[x]) {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[x] + w) {
                dis[v] = dis[x] + w;
                q.push({ dis[v], v });
            }
        }
    }
    
    cout << min(dis[n], dis[n * 2]) << endl;

    system("pause");
    return 0;
}