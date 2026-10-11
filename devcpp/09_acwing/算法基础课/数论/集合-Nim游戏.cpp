#include <bits/stdc++.h>
#define maxn 17
#define int long long
using namespace std;

int n, m, ans, p[maxn];
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> p[i];
	int k = (1 << m);
	for (int i = 1; i < k; i++) {
		int t = 1, s = 0;
		for (int j = 1; j <= m; j++) {
			if(!(i >> (j - 1) & 1)) continue; //这个位置没有数
			if(t * p[j] > n) { //如果乘着乘着发现比n大，那么接着算就没有意义了
				t = -1;
				break;
			}
			s++, t *= p[j]; //集合个数和集合之积
		}
		if(t == -1) continue;
		if(s % 2) ans += n / t; //集合个数为奇数
		else ans -= n / t; //集合个数为偶数
	}
	cout << ans << endl;
	return 0;
}
