#include <bits/stdc++.h>
#define maxn 1010
#define maxm 510
#define maxk 110
// #define inf 0x3f3f3f3f
using namespace std;

int n, A, B, see[maxn], smile[maxn], w[maxn], dp[2][maxk][maxk];
int main() {
// 	memset(dp, 0x3f, sizeof(dp));
	cin >> n >> A >> B;
	for (int i = 1; i <= n; i++) cin >> see[i] >> smile[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= A; j++)
			for (int k = 0; k <= B; k++) {
				dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
    			if (j >= see[i] && k >= smile[i]) dp[i % 2][j][k] = max(dp[(i - 1) % 2][j][k], dp[(i - 1) % 2][j - see[i]][k - smile[i]] + w[i]);
			}
	cout << dp[n % 2][A][B] << endl;
	return 0;
}
