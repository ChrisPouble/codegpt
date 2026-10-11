#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, ans = 1e9, fa[maxn], siz[maxn];
vector<int> linker[maxn], answer;
void dfs(int x, int fa) {
    siz[x] = 1;
    for (auto i : linker[x])
        if (i != fa) dfs(i, x), siz[x] += siz[i];
}

void dep1(int x, int fa) {
    int res = n - siz[x];
    for (auto i : linker[x])
        if (i != fa) res = max(siz[i], res);
    ans = min(ans, res);
    for (auto i : linker[x])
        if (i != fa) dep1(i, x);
}

int main() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) cin >> x >> y, linker[x].push_back(y), linker[y].push_back(x);
    dfs(1, 0);
    dep1(1, 0);
    cout << ans << endl;
    return 0;
}
