#include <bits/stdc++.h>
using namespace std;

int n, m, ans = -0x3f, a[210][2], f[210][210]; 
int main() {
	cin >> n;
	m = n * 2 - 1; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0];
		a[i + n][0] = a[i][0];
	}
	for (int i = 1; i <= m - 1; i++)
		a[i][1] = a[i + 1][0];
	a[m][1] = a[n][0];
	for (int i = m; i >= 1; i--) {
		f[i][i] = 0;
		for (int j = i + 1; j <= m; j++)
			for (int k = i; k < j; k++)
				f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i][0] * a[k + 1][0] * a[j][1]);
	}
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i][i + n - 1]);
	cout << ans << endl;
    return 0;
}
