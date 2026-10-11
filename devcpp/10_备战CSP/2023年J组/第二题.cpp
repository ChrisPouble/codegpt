#include <bits/stdc++.h>
#define maxn 100010
#define int long long
using namespace std;

int n, d, now, money = 1e9, ans, S[maxn], a[maxn]; //now表示车厢中的油还能走多远、money表示过去最低的油价、ans表示答案 
signed main() {
	cin >> n >> d;
	for (int i = 1; i < n; i++) cin >> S[i]; //每一个点到下一个点的距离 
	for (int i = 1; i <= n; i++) cin >> a[i]; //每一个点的加油站的油价 
	for (int i = 1; i <= n; i++) {
		now -= S[i]; //往前走
		money = min(money, a[i]); //记录最低油价 
		if(now < 0) { //需要加油了
			int t = -now;
			ans += (t + d - 1) / d * money; //需要花的钱 
			now += (t + d - 1) / d * d; //加完油之后还能走多远 
		}
	}
	cout << ans << endl;
	return 0;
}
