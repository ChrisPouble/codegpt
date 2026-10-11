#include <bits/stdc++.h>
using namespace std;

int n, sum, ans; //sum是需要花费的天数，ans是第几天采摘到最后一个苹果 
int main() {
	cin >> n;
	while(n) { //如果n不为0 
		sum++; //天数+1
		if(n % 3 == 1 && ans == 0) ans = sum; //如果可以采摘到最后一个苹果并且以前没有采摘过，则记录 
		n -= (n + 2) / 3; //这里需要向上取整 
	}
	cout << sum << " " << ans << endl; 
	return 0;
}
