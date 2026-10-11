#include <bits/stdc++.h>
#define maxn 200010
using namespace std;

int n, m, q, f[maxn][4];
vector<int> linker[maxn], tmp, nul;
void add(int x, int y) { linker[x].push_back(y); }
void dfs(int x, int k, int now) {
    tmp.push_back(x);
    if (now == k)
        return;
    for (auto v : linker[x]) dfs(v, k, now + 1);
}

signed main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 3; j++) {
            dfs(i, j, 0);
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            for (auto k : tmp) f[i][j] += k;
            tmp = nul;
        }
    cin >> q;
    while (q--) {
        int x, k;
        scanf("%d%d", &x, &k);
        printf("%d\n", f[x][k]);
    }
    return 0;
}