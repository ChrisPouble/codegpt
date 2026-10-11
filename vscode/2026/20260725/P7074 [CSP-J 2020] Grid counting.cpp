#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 10;

ll n, m, a[N][N], f[N][N][3];

int main () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
    
	memset(f, -0x3f, sizeof(f));

	f[1][1][0] = f[1][1][1] = f[1][1][2] = a[1][1];
	
    for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++)
			f[i][j][0] = max({ f[i][j - 1][0], f[i][j - 1][1], f[i][j - 1][2] }) + a[i][j];
		for (int i = 2; i <= n; i++)
			f[i][j][1] = max(f[i - 1][j][0], f[i - 1][j][1]) + a[i][j];
		for (int i = n - 1; i >= 1; i--)
			f[i][j][2] = max(f[i + 1][j][0], f[i + 1][j][2]) + a[i][j];
	}

	cout << max({ f[n][m][0], f[n][m][1], f[n][m][2] }) << endl;
	
    return 0;
}