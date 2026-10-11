#include <bits/stdc++.h>
#define maxn 100010
#define mod 1000000007
#define int long long
using namespace std;

int n, fac[maxn], infac[maxn]; //一个表示i!，一个表示i!的逆元 
int ksm(int a, int b) {
	if(b == 0) return 1;
	int t = ksm(a, b / 2);
	if(b & 1) return t * t % mod * a % mod;
	else return t * t % mod; 
}

signed main() {
	fac[0] = infac[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
		infac[i] = infac[i - 1] * ksm(i, mod - 2) % mod; //永远记住a/b=a*[b的逆元] 
	}
	cin >> n;
	while(n--) {
		int x, y;
		cin >> x >> y;
		cout << fac[x] * infac[y] % mod * infac[x - y] % mod << endl;
	} 
	return 0;
}
