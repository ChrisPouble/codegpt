#include <bits/stdc++.h>
using namespace std;

int a, b, c, ans;
signed main() {
	cin >> a >> b >> c;
	ans += a * 20 / 100; //º« 
	ans += b * 30 / 100; //À„ 
	ans += c * 50 / 100; //∫Õ 
	cout << ans << endl;
	return 0;
}
