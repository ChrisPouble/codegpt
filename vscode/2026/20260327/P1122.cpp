#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;

int n, w[N], f[N];
vector <int> linker[N];

void dfs(int x, int fa) {
    f[x] = w[x];
    for (int v : linker[x]) {
        if (v == fa) continue;
        
        dfs(v, x);
        f[x] = max(f[x], f[x] + f[v]);
    }
}

signed main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        linker[x].push_back(y);
        linker[y].push_back(x);
    }

    dfs(1, 0);

    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);

    cout << ans << endl;

    return 0;
}