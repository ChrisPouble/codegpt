#include <bits/stdc++.h>
using namespace std;

int s[5], ans, a[25], f[25][1300];
int main() {
	cin >> s[1] >> s[2] >> s[3] >> s[4];
	for (int i = 1; i <= 4; i++) {
		int res = 0, sum = 0;
		for (int j = 1; j <= s[i]; j++) {
			cin >> a[j];
			sum += a[j];
		}
		if(s[i] == 1) { //特判 
			ans += a[1];
			continue;
		}
		if(s[i] == 2) { //特判 
			ans += max(a[1], a[2]);
			continue;
		}
		//以下是01背包的板子 
		for (int j = 1; j <= s[i]; j++)
			for (int k = 0; k <= (sum + 1) / 2; k++) { //要求背包重量为sum / 2（向上取整），要求装的东西越多越好 
				f[j][k] = f[j - 1][k];
				if(k >= a[j]) f[j][k] = max(f[j - 1][k], f[j - 1][k - a[j]] + a[j]);
			}
		for (int j = 0; j <= (sum + 1) / 2; j++)
			res = max(res, f[s[i]][j]); //找到最大值 
		ans += max(res, sum - res); //两件衣服需要花费的时间为它们之间的较大值 
	}
	cout << ans << endl;
	return 0;
}
