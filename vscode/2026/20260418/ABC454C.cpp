#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, m, vis[N];
vector <int> linker[N];

int ans;
void dfs(int x, int fa) {
    ans ++, vis[x] = 1;
    for (int v : linker[x]) {
        if (vis[v] == 1) continue;
        dfs(v, x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        linker[x].push_back(y);
    }

    dfs(1, 0);
    cout << ans << endl;
    
    system("pause");
    return 0;
}