#include <bits/stdc++.h>
#define int long long
using namespace std;

int k, n, e, d;
signed main() {
	cin >> k;
	while(k--) {
		cin >> n >> e >> d;
		int l = 1, r = sqrt(n), ans = 0, m = n - e * d + 2;
		while(l <= r) {
			int mid = (l + r) / 2;
			if((m - mid) * mid == n) {
				ans = mid;
				break;
			}
			else if((m - mid) * mid < n) l = mid + 1;
			else r = mid - 1;
		}
		if(ans == 0) cout << "NO" << endl;
		else cout << ans << " " << n / ans << endl;
	}
	return 0;
}
