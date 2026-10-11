#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
const int mod = 998244353;

int n, m;
long long dp[N][N];

signed main() {
	cin >> n >> m;

	dp[0][0] = 1, m++; // 0 ~ m 共 m + 1 个元素可选
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		if (x) {
			for (int j = 1; j <= min(m, i); j++)
				dp[i][j] = dp[i - 1][j - 1];
		} else {
			for (int j = 0; j <= min(m, i); j++) 
				dp[i][j] = (dp[i - 1][j] * j + (j ? dp[i - 1][j - 1] * (m - j) % mod : 0)) % mod;
		}
	}

	long long ans = 0ll;
	for (int i = 1; i <= min(n, m); i++)
		ans = (ans + dp[n][i]) % mod;
	
    cout << ans << endl;
	return 0;
}