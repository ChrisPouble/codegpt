#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 110;

ll n, m, f[N][N];

int main(){
	cin >> m >> n, n++;
	for (int i = 1; i <= m; i++)
		f[i][1] = i * 2;
	
	for (int i = 1; i <= n; i++) {
		f[i][1] = 2;
		for (int j = 2; j <= m; j++) {
			f[i][j] += f[i - 1][j - 1] + f[i][j - 1];
		}
	}

	cout << f[n][m] << endl;
	
	return 0;
}