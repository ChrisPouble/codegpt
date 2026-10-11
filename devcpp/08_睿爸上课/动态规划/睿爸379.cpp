#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[105][105];
int a[105][105];
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	memset(f, 0, sizeof(f));
	f[1][1] = 1;
	for (int i = 1; i <= n; i++) //枚举起点 
		for (int j = 1; j <= m; j++) {
			int pos = a[i][j];
			for (int k = 0; k <= pos && i + k <= n; k++) { //找到终点 
				for (int l = 0; l + k <= pos && l + j <= m; l++) {
					if(k == 0 && l == 0) continue; //不能不懂 
					f[i + k][j + l] += f[i][j]; //加上 
					f[i + k][j + l] %= 10000; //取模 
				}
			}
		}
	cout << f[n][m] << endl;
	return 0;
}
