#include <bits/stdc++.h>
#define maxn 1510
using namespace std;

int n, fa[maxn], f[maxn][2]; //f[i][0]表不选，f[i][1]表选
vector<int>linker[maxn];
void dfs(int x, int father) {
    f[x][1] = 1;
    for (auto v:linker[x]) {
        if(v == father) continue;
        dfs(v, x);
        f[x][0] += f[v][1];
        f[x][1] += min(f[v][0], f[v][1]);
    }
}

void add(int u, int v) {
    linker[u].push_back(v);
    linker[v].push_back(u);
}

void solve() {
    for (int i = 1; i <= n; i++) while(!linker[i].empty()) linker[i].pop_back();
    memset(f, 0, sizeof(f)), memset(fa, 0, sizeof(fa));
    for (int i = 1, u, len; i <= n; i++) {
        char c;
        cin >> u >> c >> c >> len >> c; u++;
        for (int j = 1, k; j <= len; j++) cin >> k, add(u, k + 1), fa[k + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (!fa[i]) {
            dfs(i, 0);
            cout << min(f[i][0], f[i][1]) << endl;
            return;
        }
}

int main() {
    while(cin >> n) solve();
    return 0;
}
