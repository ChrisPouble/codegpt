#include <bits/stdc++.h>
#define maxn 110
#define mod 1000000007
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

void solve() {
	long long ans = 1; //虽然会 % mod，但还是需要防止爆int 
	for (auto i:s) ans = ans * (cnt[i] + 1) % mod;
	cout << ans << endl;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) add(a[i]); //每拿到一个数就进行分解质因子 
	solve(); //输出 
	return 0;
}
