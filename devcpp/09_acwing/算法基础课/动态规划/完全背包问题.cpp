#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, k, v[maxn], w[maxn], f[maxn][maxn];
signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	/*
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			for (int s = 0; s * v[i] <= j; s++) 
				f[i][j] = max(f[i][j], f[i - 1][j - v[i] * s] + s * w[i]);
	*/
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++) {
			f[i][j] = f[i - 1][j];
			if(j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
		}
	cout << f[n][k] << endl;
	return 0;
}
