#include <bits/stdc++.h>
using namespace std;

int T, m, a, b, c;
int gcd(int x, int y) {
	if(y == 0) return x;
	return gcd(y, x % y);
}

void solve() {
	cin >> a >> b >> c;
	if(a < 0) a = -a, b = -b, c = -c; //分母为正数 
	int d = b * b - 4 * a * c; //delta
	if(d < 0) { //无解 
		cout << "NO" << endl;
		return ;
	}
	if(d == 0) { //只有一个解
		int p = abs(gcd(-b, 2 * a)); //最大公因数取绝对值
		if(2 * a / p != 1) cout << -b / p << "/" << 2 * a / p << endl; //分母不为1 
		else cout << -b / p << endl;
		return ;
	}
	int k = 1;
	for (int i = 2; i * i <= d; i++)
		while(d % (i * i) == 0) { //提取出a*sqrt(b)中的 a 
			d /= i * i;
			k *= i;
		}
	if(d == 1) { //如果delta为1，说明是有理数 
		int t = -b + k;
		int p = abs(gcd(t, 2 * a)); //最大公因数取绝对值
		if(2 * a / p != 1) cout << t / p << "/" << 2 * a / p << endl; //分母不为1 
		else cout << t / p << endl;
		return ;
	}
	int p = abs(gcd(-b, 2 * a)); //最大公因数取绝对值
	if(2 * a / p != 1) cout << -b / p << "/" << 2 * a / p << "+"; //分母不为1 
	else if(-b / p != 0) cout << -b / p << "+";
	if(d == 1) {
		p = abs(gcd(k, 2 * a)); //最大公因数取绝对值
		if(2 * a / p != 1) cout << k / p << "/" << 2 * a / p << endl; //分母不为1
		else cout << k / p << endl;
		return ;
	}
	p = abs(gcd(k, 2 * a)); //最大公因数取绝对值
	if(k / p != 1) cout << k / p << "*"; //乘数不为1 
	if(2 * a / p != 1) cout << "sqrt(" << d << ")/" << 2 * a / p << endl; //分母不为1
	else cout << "sqrt(" << d << ")" << endl;
}

int main() {
	cin >> T >> m; 
	while(T--) solve();
	return 0;
}
