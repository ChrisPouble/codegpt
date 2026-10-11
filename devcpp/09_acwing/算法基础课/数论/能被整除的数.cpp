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
			if(!(i >> (j - 1) & 1)) continue;
			if(t * p[j] > n) {
				t = -1;
				break;
			}
			s++, t *= p[j];
		}
		if(t == -1) continue;
		if(s % 2) ans += n / t;
		else ans -= n / t;
	}
	cout << ans << endl;
}	return 0;

