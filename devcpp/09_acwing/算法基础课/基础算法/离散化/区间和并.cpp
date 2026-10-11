#include <bits/stdc++.h>
#define int long long
#define maxn 100010
using namespace std;

int n, ans;
struct node {
	int l, r;
}a[maxn];

bool cmp(node x, node y) {
	return x.l < y.l;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
	sort(a + 1, a + n + 1, cmp);
	int l = -2e9, r = -2e9;
	for (int i = 1; i <= n; i++) {
		if(r < a[i].l) {
			ans++;
			l = a[i].l, r = a[i].r;
		} else r = max(r, a[i].r);
	}
	cout << ans << endl;
	return 0;
}
