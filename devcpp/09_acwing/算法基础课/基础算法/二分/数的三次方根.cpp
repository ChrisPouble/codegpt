#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;

long double n; //5000 * 5000 * 5000太大了，所以要用long double 
signed main() {
	cin >> n;
	double l = -10000, r = 10000; //l和r放大点，可以防止任何误差 
	while(r - l > eps) {
		double mid = (l + r) / 2;
		if(mid * mid * mid < n) l = mid; //不用+1 
		else r = mid;
	}
	printf("%.6f", l);
	return 0;
}
