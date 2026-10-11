#include <bits/stdc++.h>
using namespace std;

int n, T, m1, m2, a[1010], b[1010], c[1010], f[1010][1010]; //f[i][j]表示在第i时刻能到达j站台的最小逗留时间 
int main() {
	cin >> n >> T >> m1 >> m2;
	for (int i = 1; i < n; i++) cin >> a[i];
	for (int i = 1; i <= m1; i++) cin >> b[i];
	for (int i = 1; i <= m2; i++) cin >> c[i];
	memset(f, 0x3f, sizeof(f));
	f[0][1] = 0;
	for (int i = 1; i <= T; i++)
		for (int j = 1; j <= n; j++) {
			if(left[i][j] && j > 1 && i - a[j - 1] >= 0) f[i][j] = min(f[i][j], f[i - a[j - 1]][j - 1]);
			if(right[i][j] && j < n && i - a[j + 1] >= 0) f[i][j] = min(f[i][j], f[i - a[j + 1]][j + 1]);
		}
	cout << f[T][n] << endl;
	return 0;
}
