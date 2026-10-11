#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;

struct node {
    int v, w;
};

int n, m, k, l, nat[N];
int dis[N][2], g[N][2];
int cnt[N];
bool pop[N];

vector<node> linker[N];

struct qnode{
    int dis, v, s;
    qnode(int a = 0, int b = 0, int c = 0) { dis = a, v = b, s = c; }
    bool operator <(const qnode &t)const{
        return dis > t.dis;
    }
};

void add(int a, int b, int c) {
    linker[a].push_back({b, c});
}

void dijkstra() {
    priority_queue<qnode> q;
    for (int i = 1; i <= n; i++)
        if (pop[i] == 1) q.push({0, i, nat[i]});
    
    while (!q.empty()) {
        int x  = q.top().v, id = q.top().s;
        int Di = q.top().dis;
        q.pop();

        if (cnt[x] <= 1) {
            // id != g[x][cnt[x] - 1] 是为了把最好的两个选项（来自不同国家的源）都找好
            if (cnt[x] == 0 || id != g[x][cnt[x] - 1]) {
                dis[x][cnt[x]] = Di, g[x][cnt[x]] = id, cnt[x]++;
                for (auto i : linker[x]) {
                    int v = i.v, w = i.w;
                    q.push({Di + w, v, id});
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i++) cin >> nat[i];
    for (int i = 1, x; i <= l; i++) cin >> x, pop[x] = 1;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dijkstra();
    for (int i = 1; i <= n; i++) {
        int ans = -1;
        if (nat[i] != g[i][0]) {
            if (cnt[i] >= 1) {
                ans = dis[i][0];
            }
        } else {
            if (cnt[i] >= 2) {
                ans = dis[i][1];
            }
        }

        cout << ans << " ";
    }
    return 0;
}