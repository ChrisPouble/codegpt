#include <bits/stdc++.h>
#define maxn 2010
#define mod 1000000007
using namespace std;

int n, c[maxn][maxn];
void init() {
	for (int i = 0; i <= 2000; i++) //枚举共有多少个金牌
		for (int j = 0; j <= i; j++) //枚举选取多少个金牌
			if(j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			else c[i][j] = 1; //选0个的情况设成1，为了方便计算
}

signed main() {
	init();
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << c[a][b] << endl;
	}
	return 0;
}
