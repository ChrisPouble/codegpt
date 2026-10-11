#include <bits/stdc++.h>
using namespace std;

int n, sum, ans, a[55], f[55][500010];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= (sum + 1) / 2; j++) { //要求背包重量为sum / 2（向上取整），要求装的东西越多越好
			f[i][j] = f[i - 1][j];
			if(j >= a[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]);
		}
	for (int i = 0; i <= (sum + 1) / 2; i++)
		ans = max(ans, f[n][i]);
	cout << abs((sum - ans) - ans) << endl;
	return 0;
}
