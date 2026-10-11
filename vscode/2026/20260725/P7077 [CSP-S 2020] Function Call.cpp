#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;
const int N = 1e5 + 10;
const int M = 1e5 + 10;

struct Func {
    int type;
    int p, v;
    vector<int> g;
} funcs[N];

int n, m;
ll a[N], mul[M], cnt[M];
int ind[M]; bool vis[M];

ll get_mul(int u) {
    if (vis[u]) return mul[u];
    vis[u] = true;
    
    if (funcs[u].type == 1) {
        mul[u] = 1;
    } else if (funcs[u].type == 2) {
        mul[u] = funcs[u].v;
    } else if (funcs[u].type == 3) {
        mul[u] = 1;
        for (int v : funcs[u].g) {
            mul[u] = (mul[u] * get_mul(v)) % mod;
        }
    }

    return mul[u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> funcs[i].type;
        if (funcs[i].type == 1) {
            cin >> funcs[i].p >> funcs[i].v;
        } else if (funcs[i].type == 2) {
            cin >> funcs[i].v;
        } else if (funcs[i].type == 3) {
            int c; cin >> c;
            for (int j = 1; j <= c; j++) {
                int x; cin >> x;
                funcs[i].g.push_back(x);
            }
        }
    }

    int q; cin >> q;
    
    funcs[0].type = 3;
    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        funcs[0].g.push_back(x);
    }

    get_mul(0);

    for (int u = 0; u <= m; u++) {
        for (int v : funcs[u].g) {
            ind[v]++;
        }
    }

    queue<int> Q;
    for (int i = 0; i <= m; i++) {
        if (ind[i] == 0) Q.push(i);
    }

    cnt[0] = 1;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();

        ll w = 1;
        for (int i = funcs[u].g.size() - 1; i >= 0; i--) {
            int v = funcs[u].g[i];
            
            cnt[v] = (cnt[v] + cnt[u] * w) % mod;
            w = (w * mul[v]) % mod;
            
            ind[v]--;
            if (ind[v] == 0) Q.push(v);
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] = (a[i] * mul[0]) % mod;
    }

    for (int i = 1; i <= m; i++) {
        if (funcs[i].type != 1) continue;
        a[funcs[i].p] = (a[funcs[i].p] + cnt[i] * funcs[i].v) % mod;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";

    return 0;
}