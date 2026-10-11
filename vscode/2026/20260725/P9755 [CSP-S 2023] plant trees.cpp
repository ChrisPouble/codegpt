#include <bits/stdc++.h>
using namespace std;
#define int128 __int128

const int N = 1e5 + 10;

int n;
int b[N], c[N], p[N], t[N], fa[N], stk[N];
vector <int> linker[N];
bool vis[N];
long long a[N];

void AddEdge(int a, int b) {
    linker[a].push_back(b);
}

void Dfs(int u, int pre) {
    fa[u] = pre;
    for (int v : linker[u]) {
        if (v != pre)
            Dfs(v, u);
    }
}

int128 Calc(int x, int128 l, int128 r) {
    if (c[x] >= 0) return (r - l + 1) * b[x] + (r - l + 1) * (l + r) / 2 * c[x];
    
    int128 T = (1 - b[x]) / c[x];
    if (T < l) return r - l + 1;
    if (T > r) return (r - l + 1) * b[x] + (r - l + 1) * (l + r) / 2 * c[x];
    
    return (T - l + 1) * b[x] + (T - l + 1) * (l + T) / 2 * c[x] + r - T;
}

bool Check(int test) {
    for (int i = 1; i <= n; i++) {
        if (Calc(i, 1, test) < a[i])
            return false;
        
        int dl = 1, dr = n, res = 0;
        while (dl <= dr) {
            int mid = (dl + dr + 1) >> 1;
            if (Calc(i, mid, test) >= a[i])
                res = mid, dl = mid + 1;
            else
                dr = mid - 1;
        }

        p[i] = i, t[i] = res;
        vis[i] = false;
    }

    sort(p + 1, p + n + 1, [](int A, int B){ return t[A] < t[B]; });

    for (int i = 1, x = 0; i <= n; i++) {
        int now = p[i], top = 0;
        while (!vis[now]) {
            vis[stk[++top] = now] = true;
            now = fa[now];
        }

        while (top) {
            if (t[stk[top--]] < ++x)
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        AddEdge(u, v);
        AddEdge(v, u);
    }

    Dfs(1, 0), vis[0] = true;

    int l = n, r = 1e9, ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (Check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << endl;
    return 0;
}