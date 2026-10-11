#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, k, a[200010], f[200010];
bool check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		//需要修行的次数：(a[i] * f[i] - x) / f[i]向上取整 
		if(a[i] * f[i] > x) cnt += (a[i] * f[i] - x + f[i] - 1) / f[i];
	return cnt <= k;
}

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> f[i];
	sort(a + 1, a + n + 1); //升序
	sort(f + 1, f + n + 1, greater<int>()); //降序 
	int l = -1, r = 1e12 + 10;
	while(l < r - 1) { //区间只剩下两个时，退出 
		int mid = (l + r) / 2;
		if(check(mid)) r = mid; //太大了，往下找 
		else l = mid;
	}
	cout << r << endl;
    return 0;
}