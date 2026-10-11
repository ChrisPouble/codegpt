#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, divisor[maxn], cnt;
void solve(int x) {
	cnt = 0;
	memset(divisor, 0, sizeof(divisor)); 
	for (int i = 1; i * i <= x; i++)
		if(x % i == 0) divisor[++cnt] = i; //把约束放进去 
	for (int i = cnt; i >= 1; i--) //这里需要倒着来枚举，原因自己想想
		if(divisor[i] * divisor[i] != x) divisor[++cnt] = x / divisor[i]; //如果不是完全平方数，就放入数组 
}

int main() {
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		solve(x);
		for (int i = 1; i <= cnt; i++) cout << divisor[i] << " ";
		cout << endl;
	}
	return 0;
}
