#include <bits/stdc++.h>
#define maxn 510
#define N 4000110 //时间最大值，注意是t+m-1 
#define inf INT_MAX //最大值 
using namespace std;

int n, m, maxa, ans = inf, a[maxn], f[N], cnt[N], sum[N]; //f[i]表示末班车发车时刻为i时，等车时间之和的最小值 
signed main() {
	scanf("%d%d", &n, &m); 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++, sum[a[i]] += a[i], maxa = max(maxa, a[i]); //取出a[i]的最大值 
	}
	for (int i = 1; i <= maxa + m - 1; i++) //不能从0开始 
		cnt[i] += cnt[i - 1], sum[i] += sum[i - 1]; //计算前缀和 
	for (int i = 0; i <= maxa + m - 1; i++) { //遍历所有时间 
		if(i >= m && cnt[i] == cnt[i - m]) { //剪枝，如果过了m分钟之后没有人到达，则等待时间则为m分钟之前的等待时间，因为没来人 
			f[i] = f[i - m];
			continue;
		}
		f[i] = cnt[i] * i - sum[i]; //初始化
		for (int j = max(0, i - 2 * m + 1); j + m <= i; j++) //j的范围
			f[i] = min(f[i], f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j])); //找出最小值 
	}
	for (int i = maxa; i <= maxa + m - 1; i++) ans = min(f[i], ans); //找答案，注意是从maxa开始 
	printf("%d\n", ans);
	return 0;
}
