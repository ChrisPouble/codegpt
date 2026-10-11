#include <bits/stdc++.h>
#define maxn 500010
#define int long long //不开long long见祖宗 
using namespace std;

int n, d, k, sum, f[maxn];
int l = 0, r, ans = 1000000000;
struct node {
	int x, s;
}a[maxn];

bool check(int x) {
	for (int i = n; i >= 0; i--) { //注意要枚举到0
		f[i] = a[i].s; //初始化
		for (int j = i + 1; a[j].x - a[i].x <= d + x && j <= n; j++) //不能越界
			if(a[j].x - a[i].x >= d - x && f[j] + a[i].s > f[i]) f[i] = f[j] + a[i].s; //如果能更新则更新
	}
	return f[0] >= k; //答案如果满足条件
}

signed main() {
	scanf("%lld%lld%lld", &n, &d, &k);
	for (int i = 1, last = 0; i <= n; i++) {
		scanf("%lld%lld", &a[i].x, &a[i].s);
		if(a[i].s > 0) sum += a[i].s, r = max(a[i].x - last, r), last = a[i].x; //记录两个正整数分值之间的距离值的距离（伦敦大雾），取其中最大的 
	}
	if(sum < k) { //如果所有正整数的分值的和<k，说明没有方法 
		puts("-1");
		return 0;
	}
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1; //找到答案，记录答案，缩小r
		else l = mid + 1; //否则放大l
	}
	printf("%lld\n", ans);
	return 0;
}
