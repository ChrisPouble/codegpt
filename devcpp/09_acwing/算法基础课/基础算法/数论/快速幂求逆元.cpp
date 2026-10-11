#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

int ksm(int a, int b, int p) { //底数、指数、模数 
	int res = 1; //初始化
	while(b) {
		if(b & 1) res = res * a % p; //奇数情况 
		b = b / 2; //除以2 
		a = a * a % p; //倍增 
	}
	return res;
}

int n; 
signed main() {
	cin >> n;
	while(n--) {
		int a, p;
		cin >> a >> p;
		int ans = ksm(a, p - 2, p); //求逆元
		if(a * ans % p != 1) cout << "impossible" << endl; //如果没有逆元 
		else cout << ans << endl;
	}
	return 0;
}
