#include <bits/stdc++.h>
#define maxn 100010
#define int long long //不开long long见祖宗 
using namespace std;

int n, m, p1, s1, s2, sum1, sum2, ans_cha = 1000000000, ans_i, a[maxn]; 
signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	scanf("%lld%lld%lld%lld", &m, &p1, &s1, &s2);
	a[p1] += s1; //加上s1个兵 
	for (int i = 1; i < m; i++) sum1 += abs(m - i) * a[i]; //龙势力 
	for (int i = m + 1; i <= n; i++) sum2 += abs(m - i) * a[i]; //虎势力 
	for (int i = 1; i <= n; i++) {
		if(i == m && abs(sum1 - sum2) < ans_cha) { //i=m的情况
			ans_cha = abs(sum1 - sum2);
			ans_i = i;
		}
		if(i < m && abs(sum1 + abs(m - i) * s2 - sum2) < ans_cha) { //i < m的情况
			ans_cha = abs(sum1 + abs(m - i) * s2 - sum2);
			ans_i = i;
		}
		if(i > m && abs(sum2 + abs(m - i) * s2 - sum1) < ans_cha) { //i > m的情况
			ans_cha = abs(sum2 + abs(m - i) * s2 - sum1);
			ans_i = i;
		}
	}
	printf("%lld\n", ans_i); //输出 
	return 0;
}
