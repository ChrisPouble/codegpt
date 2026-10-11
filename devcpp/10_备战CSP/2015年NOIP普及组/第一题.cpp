#include <bits/stdc++.h>
using namespace std;

int k, day = 1, cnt, sum; //k是输入的数据，day是连续n天，cnt是在这连续n天中已经过了几天，sum是答案 
int main() {
	cin >> k;
	while(k--) { //天数一点一点的减少
		if(cnt == day) day++, cnt = 0; //如果n天过完了，则进入下一个n+1天里 
		cnt++, sum += day; //每过一天，加n进步 
	}
	cout << sum << endl;
	return 0;
}
