#include <bits/stdc++.h>
#define mod 10
using namespace std;

int n, ans, dp[15][15][15][15][15];
int main() {
	cin >> n;
	for (int j = 1; j <= n; j++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		for (int i = 1; i <= 9; i++) {
			dp[(a + i) % mod][b][c][d][e]++;
			dp[a][(b + i) % mod][c][d][e]++;
			dp[a][b][(c + i) % mod][d][e]++;
			dp[a][b][c][(d + i) % mod][e]++;
			dp[a][b][c][d][(e + i) % mod]++;
			dp[(a + i) % mod][(b + i) % mod][c][d][e]++;
			dp[a][(b + i) % mod][(c + i) % mod][d][e]++;
			dp[a][b][(c + i) % mod][(d + i) % mod][e]++;
			dp[a][b][c][(d + i) % mod][(e + i) % mod]++;
		}
	}
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k <= 9; k++)
				for (int x = 0; x <= 9; x++)
					for (int y = 0; y <= 9; y++)
						if(dp[i][j][k][x][y] == n) ans++;
	cout << ans << endl;
	return 0;
}
