#include <bits/stdc++.h>
#define maxn 200010
#define inf 0x3f3f3f3f
using namespace std;

int n, m, k, ans = inf, s[maxn];
bool vis[maxn][2];
struct node {
    int x, pts, st;  //当前走到的点、当前走了多少步、当前状态0/1
};

struct edge {
    int to, w;
};

vector<edge> linker[maxn];
void add(int x, int y, int w) { linker[x].push_back({ y, w }); }

void bfs() {
    queue<node> q;
    q.push({ 1, 0, 0 }), q.push({ 1, 0, s[1] }), vis[1][s[1]] = 1, vis[1][0] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int pts = q.front().pts;
        int st = q.front().st;
        q.pop();
        // cout << x << " " << pts << " " << st << endl;
        if (x == n)
            ans = min(ans, pts);
        for (auto i : linker[x]) {
            // cout << "Fasfdadfsdafsdf" << endl;
            int v = i.to, w = i.w;
            int state = (st ^ s[v]);
            if (st == 1 && i.w == 0 && (!vis[v][state] || !vis[v][st])) {
                vis[v][state] = 1, vis[v][st] = 1;
                q.push({ v, pts + 1, st });
                if (state != st)
                    q.push({ v, pts + 1, state });
            } else if (st == 0 && i.w == 1 && (!vis[v][state] || !vis[v][st])) {
                vis[v][state] = 1, vis[v][st] = 1;
                q.push({ v, pts + 1, st });
                if (state != st)
                    q.push({ v, pts + 1, state });
            }
        }
    }
}

signed main() {
    cin >> n >> m >> k;
    for (int i = 1, x, y, type; i <= m; i++) {
        cin >> x >> y >> type;
        add(x, y, type), add(y, x, type);
    }
    for (int i = 1, x; i <= k; i++) cin >> x, s[x] = 1;
    bfs();
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}