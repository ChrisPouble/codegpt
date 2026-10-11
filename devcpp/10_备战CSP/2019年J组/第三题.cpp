#include <bits/stdc++.h>
#define day 110
#define N 110
using namespace std;

int T, n, m, ans, price[day][N], dp[10010];
signed main() {
	cin >> T >> n >> m;
	ans = m; //刚开始的时候的钱数
	for (int i = 1; i <= T; i++)
		for (int j = 1; j <= n; j++)
			cin >> price[i][j];
	for (int i = 1; i < T; i++) { //从1枚举到T-1 
		memset(dp, 0, sizeof(dp)); //初始化 
		for (int j = 1; j <= n; j++) //枚举n个纪念品
			for (int k = price[i][j]; k <= ans; k++) //枚举背包边界
				dp[k] = max(dp[k], dp[k - price[i][j]] + price[i + 1][j] - price[i][j]); //状态转移方程 
		ans += dp[ans]; //加上今天的盈利
	}
	cout << ans << endl; //答案 
	return 0;
}
