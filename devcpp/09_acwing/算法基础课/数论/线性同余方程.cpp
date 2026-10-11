#include <bits/stdc++.h>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0; //b = 0的情况 
		return a;
	}
	int d = exgcd(b, a % b, y, x); //把x和y颠倒过来，方便后面的计算 
	y -= a / b * x; //x不用动，y要动 
	return d;
}

int n, a, b;
signed main() {
	scanf("%lld", &n);
	while(n--) {
		int a, b, m, x = 0, y = 0;
		scanf("%lld%lld%lld", &a, &b, &m);
		int d = exgcd(a, m, x, y); //求出gcd
		if(b % d) printf("impossible\n"); //无解 
		else {
			exgcd(a, m, x, y); //扩展欧几里得算法 
			printf("%lld\n", x * (b / d) % m); //答案 
		}
	}
	return 0;
}
