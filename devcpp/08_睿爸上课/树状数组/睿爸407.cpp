#include <bits/stdc++.h>
#define maxn 50010
using namespace std;

long long n, m, k, p, vis[maxn];
long long gcd(long long x, long long y) { //求最大公约数 
	return x == 0 ? y : gcd(y % x, x);
}

int main() {
	cin >> n >> m;
	if(m < 3) { //特判 
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		long long x, y; cin >> x >> y;
		vis[x]++; //差分 
		vis[y + 1]--;
	}
	for (int i = 1; i <= n; i++) {
		k += vis[i]; //加上vis值
		if(k >= 3) p += k * (k - 1) * (k - 2) / 6; //如果这个点被k个区间覆盖了，那么加上k * (k - 1) * (k - 2) / 6
	}
	long long q = m * (m - 1) * (m - 2) / 6; //总方案数 
	long long t = gcd(p, q); 
	p /= t; //约分 
	q /= t;
	if(q == 1) cout << p; //如果可以整除，那么直接输出 
	else cout << p << "/" << q << endl; //否则输出分数 
	return 0;
}
