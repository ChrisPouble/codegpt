#include <bits/stdc++.h>
using namespace std;

int n, f[1010][2];
int main() {
	cin >> n;
	if(n == 1) {
		cout << 9 << endl;
		return 0;
	}
	f[1][0] = 9, f[1][1] = 1; 
	for (int i = 2; i <= n - 1; i++)
		f[i][0] = f[i - 1][1] + f[i - 1][0] * 9, f[i][1] = f[i][1] * 9 + f[i][0];
	f[n][0] = f[n - 1][1] + f[n - 1][0] * 8;
	cout << f[n][0] << endl;
	return 0;
}
