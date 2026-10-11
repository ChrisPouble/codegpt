#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n = 4, m, a[maxn] = {0, 10, 20, 50, 100}, f[10][maxn];
signed main() {
	cin >> m;
	for (int i = 0; i <= n; i++) f[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= a[i]) f[i][j] = f[i - 1][j] + f[i][j - a[i]]; //只有能装得下才可以加上f[i - 1][j - a[i]]
        }
	cout << f[n][m] << endl;
	return 0;
}
