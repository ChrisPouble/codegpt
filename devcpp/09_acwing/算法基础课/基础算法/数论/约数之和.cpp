#include <bits/stdc++.h>
#define maxn 110
#define mod 1000000007
#define int long long //十年OI一场空，不开long long见祖宗 
using namespace std;

int n, a[maxn];
map<int, int>cnt; //记录质因数的个数
set<int>s; //s表示一共有哪些质因数
void add(int x) { //分解质因数 
	for (int i = 2; i * i <= x; i++) //从2枚举到sqrt(x)
		if(x % i == 0) { //发现能被i整除 
			int sum = 0; //统计有多少个因数 
			while(x % i == 0) x /= i, sum++; //每统计一个就除以i，并且sum+1 
			s.insert(i); //把质因数加入进去
			cnt[i] += sum; //质因数的个数进行更新
		}
	if(x > 1) s.insert(x), cnt[x]++; //特判 
}

int work(int x, int k) { //求x^0+x^1+x^2+...+x^k的和 
	int last = 1, sum = 1;
	for (int i = 1; i <= k; i++) last = (last * x) % mod, sum = (sum + last) % mod; 
	return sum;
}

void solve() {
	int ans = 1;
	for (auto i:s) ans = ans * work(i, cnt[i]) % mod;
	cout << ans << endl;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) add(a[i]);
	solve();
	return 0;
}
