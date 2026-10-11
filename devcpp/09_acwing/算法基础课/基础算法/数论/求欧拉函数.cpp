#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, a, cnt, divisor[maxn];
void add(int x) {
	cnt = 0;
	memset(divisor, 0, sizeof(divisor));
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) { //找到因数 
			while(x % i == 0) x /= i; //除尽 
			divisor[++cnt] = i; //放入质数集合 
		}
	if(x > 1) divisor[++cnt] = x; //特判 
}

int solve(int x) {
	int ans = x;
	for (int i = 1; i <= cnt; i++)
		ans = ans / divisor[i] * (divisor[i] - 1); //注意这里有可能会爆int 
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		add(a); //分解质因数
		cout << solve(a) << endl; //输出欧拉函数 
	}
	return 0;
}
