#include <bits/stdc++.h>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0; //b = 0的情况 
		return a;
	}
    int x1, y1;
    int d = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
	return d;
}

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int mod(int a, int b) {
    return ((a % b) + b) % b;
}

int n, a1, m1;
signed main() {
	scanf("%lld%lld%lld", &n, &a1, &m1);
	for (int i = 1, a2, m2; i < n; i++) {
		scanf("%lld%lld", &a2, &m2);
		int c = m2 - m1, k1 = 0, k2 = 0;
		int d = exgcd(a1, -a2, k1, k2); //扩展欧几里得 
		if((m2 - m1) % d) { //不能整除 
			cout << -1 << endl;
			return 0;
		}
		k1 = mod(k1 * (m2 - m1) / d, abs(a2 / d)); //前面是为了找解，后面是为了找最小解
		m1 = abs(a1 * k1 + m1); //为了下一次做准备 
		a1 = abs(a1 / d * a2); 
	}
	cout << m1 << endl;
	return 0;
}
