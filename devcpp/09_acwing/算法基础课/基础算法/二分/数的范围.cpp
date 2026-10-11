#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, q, k, a[maxn];
int left(int x) {
	int l = 1, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(a[mid] == x) ans = mid, r = mid - 1;
		else if(a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

int right(int x) {
	int l = 1, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(a[mid] == x) ans = mid, l = mid + 1;
		else if(a[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}

signed main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while(q--) {
		cin >> k;
		int l = left(k), r = right(k);
		if(l == -1 && r == -1) cout << "-1 -1" << endl;
		else cout << l - 1 << " " << r - 1 << endl;
	}
	return 0;
}
