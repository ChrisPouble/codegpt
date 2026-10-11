#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int n, ans = 1;
int ksm(int a, int b, int p) { //底数、指数、模数 
	if(b == 1) return a; //边界条件 
	int t = ksm(a, b >> 1, p); //进行分治 
	if(b & 1) return t * t % p * a % p; //如果b为奇数 
	else return t * t % p; //如果b为偶数 
}

signed main() {
	cin >> n;
	 //首先算出C(n, 2n)
	for (int i = 2 * n; i > n; i--) ans = ans * i % mod; 
	for (int i = 1; i <= n; i++) ans = ans * ksm(i, mod - 2, mod) % mod;
	//之后乘以(n + 1)的逆元就行了 
	ans = ans * ksm(n + 1, mod - 2, mod) % mod;
	cout << ans << endl;
	return 0;
}
