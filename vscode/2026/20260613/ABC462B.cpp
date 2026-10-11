#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, vis[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int m, x; cin >> m;
        while (m--) cin >> x, vis[x][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            cnt += vis[i][j];
        
        cout << cnt << " ";
        for (int j = 1; j <= n; j++)
            if (vis[i][j]) cout << j << " ";
        cout << endl;
    }

    return 0;
}

/*
1. 坑点考点
2. 回顾以前
3. 超级总结
*/