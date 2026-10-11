#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;

int z[N << 1];
int f[N], g[N];
string s, t;

// str[0] 是占位符，有效字符串从下标 1 开始
void exkmp(const string &str) {
    int n = (int)str.size() - 1;
    int l = 1, r = 0;
    z[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (i > r) {
            z[i] = 0;
        } else {
            z[i] = min(z[i - l + 1], r - i + 1);
        }

        while (i + z[i] <= n &&
               str[i + z[i]] == str[z[i] + 1]) {
            ++z[i];
        }

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z[1] = n;
}

struct PredecessorDSU {
    int fa[N], sz[N], mn[N];

    void init(int n) {
        // 候选值 0..n 映射到编号 1..n+1
        // 编号 0 是哨兵，代表候选值 -1
        for (int i = 0; i <= n + 1; i++) {
            fa[i] = mn[i] = i;
            sz[i] = 1;
        }
    }

    int find(int u) {
        return fa[u] == u ? u : fa[u] = find(fa[u]);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        fa[v] = u;
        sz[u] += sz[v];
        mn[u] = min(mn[u], mn[v]);
    }

    void erase(int y) {
        int id = y + 1;
        merge(id, id - 1);
    }

    // 不超过 x 的最大未删除值，不存在时返回 -1
    int see(int x) {
        return mn[find(x + 1)] - 1;
    }
} dsu;  // 大数组放在全局，避免栈溢出

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n >> s >> t;

    // s、t 本身采用 0-based 下标
    // 拼接字符串中，第二个串的首字符位于 n+2

    // f[x] = LCP(s[x..], t)
    exkmp(" " + t + "#" + s);
    for (int x = 0; x < n; x++)
        f[x] = z[n + 2 + x];

    // g[y] = LCP(t[y..], s)
    exkmp(" " + s + "#" + t);
    for (int y = 0; y < n; y++)
        g[y] = z[n + 2 + y];
    
    g[n] = 0;  // 空后缀

    dsu.init(n);

    int ans = 0;

    // s 的前缀 = XY，t 的前缀 = YX
    // |X| = x，|Y| = y
    for (int x = 0; x < n; x++) {
        int y = dsu.see(f[x]);

        while (y != -1 && g[y] < x) {
            dsu.erase(y);
            y = dsu.see(y);
        }

        if (y != -1) {
            ans = max(ans, x + y);
        }
    }

    cout << ans << '\n';
    return 0;
}