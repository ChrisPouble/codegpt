#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e6 + 10;

int n, m, fa[N];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int xx = find(x), yy = find(y);
    fa[xx] = yy;
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        fa[i] = i;
    
    int opt, x, y;
    while (m--) {
        cin >> opt >> x >> y;

        if (opt == 1) merge(x, y);
        else {
            if (find(x) != find(y)) cout << "NO\n";
            else cout << "YES\n";
        }
    }

    system("pause");
    return 0;
}