#include <bits/stdc++.h>
#define maxn 15
using namespace std;

int n, m, a[maxn][maxn], f[maxn][maxn][maxn][maxn];
int my_max(int x, int s, int w, int l) {
    return max(x, max(s, max(w, l)));
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	f[1][1][1][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = i + 1; k <= n; k++)
                for (int o = 1; o < j; o++) {
                    int walk = my_max(f[i - 1][j][k - 1][o], f[i - 1][j][k][o - 1], f[i][j - 1][k - 1][o], f[i][j - 1][k][o - 1]);
                    f[i][j][k][o] += a[i][j] + a[k][o] + walk;
//                    if (i == k && j == o) f[i][j][k][o] -= a[i][j];
                }
    cout << f[n - 1][m][n][m - 1] << endl; //这里是到不了终点的 
    return 0;
}
