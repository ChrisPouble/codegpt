#include <bits/stdc++.h>
#define maxn 1000010
#define int long long
using namespace std;

int n, ans, cnt, phi[maxn], prime[maxn];
bool is_prime[maxn];
int solve(int x) {
	phi[1] = 1; //初始化 
	is_prime[1] = 1; //初始化
	for (int i = 2; i <= n; i++) {
		if(!is_prime[i]) prime[++cnt] = i, phi[i] = i - 1; //标记质数，求质数的欧拉函数 
		for (int j = 1; prime[j] * i <= n; j++) {
			is_prime[prime[j] * i] = 1;
			if(i % prime[j] == 0) {
				phi[prime[j] * i] = phi[i] * prime[j]; //如果prime[j]能整除i 
				break;
			} else phi[prime[j] * i] = phi[i] * (prime[j] - 1); //如果prime[j]不能整除i 
		}
	}
}

signed main() {
	cin >> n;
	solve(n);
	for (int i = 1; i <= n; i++) ans += phi[i]; //求和 
	cout << ans << endl;
	return 0;
}
