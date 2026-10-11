#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n;
void solve(int x) {
	for (int i = 2; i * i <= x; i++) //从2枚举到sqrt(x)
		if(x % i == 0) { //发现能被i整除 
			int sum = 0; //统计有多少个因数 
			while(x % i == 0) x /= i, sum++; //每统计一个就除以i，并且sum+1 
			cout << i << " " << sum << endl; //输出 
		}
	if(x > 1) cout << x << " " << 1 << endl; //特判 
	cout << endl;
}

signed main() {
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		solve(x); 
	}
	return 0;
}
