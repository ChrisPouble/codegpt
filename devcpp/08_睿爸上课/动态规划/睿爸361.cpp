#include <bits/stdc++.h> 
using namespace std;

int n, ans, sum;
bool f[110][400010];
struct node {
	int s, w;
}a[110];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].s >> a[i].w;
		sum += a[i].s * a[i].w; //最多可以构成多少重量 
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) //枚举所有砝码 
		for (int j = 0; j <= sum; j++) //枚举重量 
			for (int k = 0; k <= a[i].s; k++) //枚举要那多少种这样的砝码 
				if(j >= k * a[i].w && f[i - 1][j - k * a[i].w]) f[i][j] = 1; //比较容易，自己想想为什么 
	for (int i = 1; i <= sum; i++)
		ans += f[n][i]; //算答案 
	cout << "Total=" << ans << endl; 
	return 0;
}
