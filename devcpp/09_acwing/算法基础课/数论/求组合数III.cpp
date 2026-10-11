#include <bits/stdc++.h>
#define maxn 100010
#define int long long
using namespace std;

int n, mod, fac[maxn], infac[maxn]; //一个表示i!，一个表示i!的逆元 
int ksm(int a, int b) {
	if(b == 0) return 1;
	int t = ksm(a, b / 2);
	if(b & 1) return t * t % mod * a % mod;
	else return t * t % mod; 
}

int C(int x, int y) { //直接根据定义来求 
	int res = 1;
	for (int i = 1, j = x; i <= y; i++, j--) {
		res = res * j % mod;
		res = res * ksm(i, mod - 2) % mod;
	}
	return res % mod;
}

int lucas(int x, int y) { //lucas定理 
	if(x < mod && y < mod) return C(x, y);
	return C(x % mod, y % mod) * lucas(x / mod, y / mod) % mod;
}

signed main() {
	cin >> n;
	while(n--) {
		int x, y;
		cin >> x >> y >> mod;
		cout << lucas(x, y) << endl;
	} 
	return 0;
}
