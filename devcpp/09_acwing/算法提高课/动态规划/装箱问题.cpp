#include <bits/stdc++.h>
#define V 20010
#define maxn 35
using namespace std;

int n, m;
int f[maxn][V], a[maxn];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		f[i][0] = 0; //初始化 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if(j >= a[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i]] + a[i]); //找到最大值 
			else f[i][j] = f[i - 1][j];
	cout << m - f[n][m] << endl;
    return 0;
}
