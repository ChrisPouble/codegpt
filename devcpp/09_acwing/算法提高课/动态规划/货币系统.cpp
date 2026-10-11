#include <bits/stdc++.h>
#define maxn 3010
#define int long long
using namespace std;

int n, m, a[maxn], f[20][maxn];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++) {
		    for (int k = 0; k * a[i] <= j; k++)
    			f[i][j] += f[i - 1][j - k * a[i]];
		}
	cout << f[n][m] << endl;
	return 0;
}
