#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int ksm_1(int a, int b, int p) { //底数、指数、模数 
	if(b == 1) return a; //边界条件 
	int t = ksm_1(a, b >> 1, p); //进行分治 
	if(b & 1) return t * t % p * a % p; //如果b为奇数 
	else return t * t % p; //如果b为偶数 
}

int ksm_2(int a, int b, int p) {
	int res = 1; //初始化
	while(b) {
		if(b & 1) res = res * a % p; //奇数情况 
		b = b >> 1; //进行位移，即除以2 
		a = a * a % p; //并且倍增 
	}
	return res;
}

int n, a, b, p;
signed main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d%d", &a, &b, &p);
		printf("%d\n", ksm_2(a, b, p));
	}
	return 0;
}
