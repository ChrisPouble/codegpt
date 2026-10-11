#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int n, a[N];
int x, maxx, minn;

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		
        maxx = -inf, minn = inf;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			maxx = max(maxx, a[i] + x);
			minn = min(minn, a[i] - x);
		}

		double ans = (maxx + minn) / 2.0;

		printf("%.6lf\n", ans);
	}
    
	return 0;
}