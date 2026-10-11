#include <bits/stdc++.h>
#define maxn 1010
#define maxm 110
#define inf 0x3f3f3f3f
using namespace std;

int n, A, B, a[maxn], b[maxn], c[maxn], dp[maxn][maxm][maxm];
int main() {
	memset(dp, 0x3f, sizeof(dp));
	cin >> A >> B >> n;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	for (int i = 1; i <= n; i++)
	    for (int j = 0; j <= A; j++)
	        for (int k = 0; k <= B; k++) {
	            dp[i][j][k] = min(dp[i - 1][j][k], dp[i - 1][max(j - a[i], 0)][max(k - b[i], 0)] + c[i]);
	        }
	cout << dp[n][A][B] << endl; 
	return 0;
}
