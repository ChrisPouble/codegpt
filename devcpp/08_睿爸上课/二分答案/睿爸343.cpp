#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m, l = 0, r = 1e9, ans, a[100010];
bool check(int x) {
	int sum = 0, res = 1;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if(sum > x) res++, sum = a[i];
	}
	return res <= m; //是否可以
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = max(l, a[i]); //确定边界 
	}
	while(l <= r) {
		int mid = (l + r) / 2; //枚举 
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}
