#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, r = 1, later = maxn, a[maxn], ans[maxn];
int query_max() {
	int res = 0;
	for (int i = 1; i <= n; i++)
		if(later > a[i]) res = max(res, a[i]);
	return res;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while(r <= n) {
		int ma = query_max(), k = 0;
		for (int j = 1; j <= n; j++)
			if(a[j] == ma) k++, ans[j] = r;
		later = ma, r += k;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}
