#include<bits/stdc++.h>
using namespace std;

bool f[110][2010]; //f[i][j]表示取i个，是否重量可以凑成j 
int n, sum, a[110];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) //枚举所有物品 
		for (int j = n; j >= 0; j--) //枚举装几个物品（请注意：这里是倒序） 
			for (int k = sum; k >= 0; k--) //枚举是否能凑成这个重量 
				if(f[j][k]) f[j + 1][k + a[i]] = 1; //如果可以，那么就加上a[i]这个物品 
	int ans = sum;
	for (int i = 0; i <= sum; i++)
		if(f[n / 2][i]) ans = min(ans, abs((sum - i) - i)); //取最小值 
	cout << ans << endl;
	return 0;
}
