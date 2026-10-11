#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e4 + 10;

int n, k, a[N];
int siz[N];
bitset <N> tree[N];
vector <int> linker[N];

bool Could;
void dfs(int u) {
    siz[u] = (a[u] == -1 ? 1 : 0);

    if (a[u] == k) siz[u] = N; // 标记无解
    for (int v : linker[u]) {
        dfs(v);
        siz[u] += siz[v];
        tree[u] |= tree[v];
    }

    if (siz[u] <= 1 && (~tree[u])._Find_first() == k) Could = true;
    if (siz[u] == 1 && tree[u].count() == k - 1) Could = true;
}

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        linker[i].clear();
        tree[i].reset();
    }
    
    for (int i = 2, fa; i <= n; i++) {
        cin >> fa;
        linker[fa].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        // 这里的 a[i] <= k 方便等会判断能否构成 mex = k
        if (a[i] != -1 && a[i] <= k)
            tree[i].set(a[i]);
    }

    Could = false, dfs(1);
    cout << (Could ? "Alice\n" : "Bob\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}