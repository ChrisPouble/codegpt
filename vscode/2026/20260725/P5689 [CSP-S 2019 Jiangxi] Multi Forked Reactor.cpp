#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
const int N = 3e5 + 10;

ll fac[N], inv[N];

// 快速幂求逆元
ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1ll) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2ll;
    }
    return res;
}

// 预处理阶乘和阶乘的乘法逆元，为快速求组合数做准备
void init() {
    fac[0] = inv[0] = 1ll;
    for (int i = 1; i < N; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }

    inv[N - 1] = power(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 1; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

// O(1) 提取组合数 C(n, k)
ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int n, q, fa[N];
ll sz[N], f[N];

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        fa[i] = i;
        sz[i] = 1;
        f[i] = 1;
    }

    ll ans = 0;

    for (int i = 0; i < q; i++) {
        int type; cin >> type;
        if (type == 1) {
            ll xp, yp; cin >> xp >> yp;

            int x = (xp + ans) % n;
            int y = (yp + ans) % n;
            
            int root_x = find(x);
            int root_y = find(y);
            
            if (root_x != root_y) {
                fa[root_x] = root_y;
                f[root_y] = f[root_x] * f[root_y] % mod * C(sz[root_x] + sz[root_y] - 1, sz[root_x]) % mod;
                sz[root_y] += sz[root_x];
            }
        } else if (type == 2) {
            ll xp; cin >> xp;
            int x = (xp + ans) % n;
            int root_x = find(x);
            
            ans = f[root_x];
            cout << ans << "\n";
        }
    }

    return 0;
}