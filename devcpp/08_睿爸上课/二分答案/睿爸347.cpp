#include<bits/stdc++.h>
using namespace std;

int n, k, sum, ans, Max, a[10010];
bool check(int x) {
	int res = 0;
	for (int i = 1; i <= n; i++)
		res += a[i] / x;
	return res >= k; //是否可以 
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		Max = max(Max, a[i]);
	}
	int l = 0, r = Max; //边界 
	while(l <= r) {
		int mid = (l + r) / 2; //枚举s 
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
