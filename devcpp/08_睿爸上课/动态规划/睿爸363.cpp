#include <bits/stdc++.h> 
using namespace std;

int n, x, y, w, a[35][35], f[35][35][35][35];
int main() {
	cin >> n;
	while(cin >> x >> y >> w) { //输入 
		if(x == 0 && y == 0 && w == 0) break; //退出 
		a[x][y] = w;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				for (int l = 1; l <= n; l++) {
					int t1 = max(f[i - 1][j][k - 1][l], f[i - 1][j][k][l - 1]); //记录 
					int t2 = max(f[i][j - 1][k - 1][l], f[i][j - 1][k][l - 1]); //记录 
					f[i][j][k][l] = max(t1, t2) + a[i][j] + a[k][l]; //求最大值 
					if(i == k && j == l) f[i][j][k][l] -= a[i][j]; //如果位置相同，则减去其中一个 
				}
	cout << f[n][n][n][n] << endl; //答案 
	return 0;
}
