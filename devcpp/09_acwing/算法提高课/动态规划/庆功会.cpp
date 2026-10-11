#include <bits/stdc++.h>
#define maxn 510
#define maxm 6010
using namespace std;

int n, V, v[maxm], w[maxm], s[maxm], f[maxn][maxm];
signed main() {
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= V; j++)
			for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + k * w[i]);
	cout << f[n][V] << endl;
	return 0;
}
