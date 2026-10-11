#include <bits/stdc++.h>
using namespace std;

int ans, l, r;
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	cin >> l >> r;
	for (int i = 1; i <= 12; i++) //枚举月份 
		for (int j = 1; j <= month[i]; j++) { //枚举年份 
			int t = (j % 10 * 10 + j / 10) * 1000000 + (i % 10 * 10 + i / 10) * 10000 + i * 100 + j; //得出前四位 
			if(t >= l && t <= r) ans++; //找到一个合乎题目条件的年份 
		}
	cout << ans << endl;
	return 0;
}
