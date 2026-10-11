#include <bits/stdc++.h>
#define int long long
using namespace std;

int A, B, L;
int gcd(int x, int y) { //求最大公约数 
	if(y == 0) return x;
	return gcd(y, x % y);
}

signed main() {
	cin >> A >> B >> L;
	int ansa = L, ansb = 1; //初始化，记录最优解 
	for (int i = 1; i <= L; i++)
		for (int j = 1; j <= L; j++)
			if(gcd(i, j) == 1 && i * B >= A * j && ansa * j > ansb * i) ansa = i, ansb = j; //判断条件 
	cout << ansa << " " << ansb << endl;
	return 0;
}
