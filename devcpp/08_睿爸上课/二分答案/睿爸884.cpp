#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, ans, a[100010];
bool check(int x) {
	int sum = 0;
	vector<int>vec;
	for (int i = 1; i <= n; i++)
		vec.push_back(a[i] + x * i); //把每个值都放进去 
	sort(vec.begin(), vec.end()); //排序，尽量去花费最少的装饰品 
	for (int i = 0; i < x; i++)
		sum += vec[i]; //把花的钱加上 
	return sum <= m; //判断是否买得起 
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1, r = n; //边界 
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) ans = max(ans, mid), l = mid + 1; //买得起就记录答案，并且接着找更大的答案 
		else r = mid - 1; //否则只能往下找 
	}
	cout << ans << endl;
	return 0;
}
