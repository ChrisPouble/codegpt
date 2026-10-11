#include<bits/stdc++.h>
using namespace std;

int g, v, n, sum, ans, f[2][400][400]; //f[i][j][k]表示取前i个，重量为j，体积为k时的最大完美值 
struct node {
	int t, g, v; //完美值、重量、体积 
}a[400];

int main() {
	cin >> g >> v >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].t >> a[i].g >> a[i].v;
	for (int i = 1; i <= n; i++) //枚举所有物品 
		for (int j = 0; j <= g; j++) //枚举重量
			for (int k = 0; k <= v; k++) { //枚举体积 
				f[i % 2][j][k] = f[(i - 1) % 2][j][k];
				if(j >= a[i].g && k >= a[i].v) f[i % 2][j][k] = max(f[(i - 1) % 2][j][k], f[(i - 1) % 2][j - a[i].g][k - a[i].v] + a[i].t);
			}
	cout << f[n % 2][g][v] << endl;
	return 0;
}
