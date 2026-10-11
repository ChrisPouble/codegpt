#include <bits/stdc++.h>
#define maxn 310
#define inf 0x3f3f3f3f
using namespace std;

int n, m, a[maxn], f[maxn][maxn], w[maxn][maxn];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			for (int k = i; k <= j; k++)
				w[i][j] += a[k];
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = n; i >= 1; i--)
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = inf;
			for (int k = i; k < j; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + w[i][j]);
		}
	cout << f[1][n] << endl;
	return 0;
}
