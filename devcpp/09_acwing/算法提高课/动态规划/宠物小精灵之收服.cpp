#include <bits/stdc++.h>
#define maxn 1010
#define maxm 510
#define maxk 110
// #define inf 0x3f3f3f3f
using namespace std;

 int n, A, B, see[maxn], smile[maxn], dp[maxn][maxm];
int main() {
// 	memset(dp, 0x3f, sizeof(dp));
	cin >> A >> B >> n;
	B--;
	for (int i = 1; i <= n; i++) cin >> see[i] >> smile[i];
	for (int i = 1; i <= n; i++)
		for (int j = A; j >= see[i]; j--)
			for (int k = B; k >= smile[i]; k--) {
				// dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
    			dp[j][k] = max(dp[j][k], dp[j - see[i]][k - smile[i]] + 1);
			}
	int k = B;
	while(k > 0 && dp[A][k - 1] == dp[A][B]) k--;
	cout << dp[A][B] << " " << B + 1 - k << endl;
	return 0;
}
