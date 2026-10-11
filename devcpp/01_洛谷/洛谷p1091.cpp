#include <bits/stdc++.h>
using namespace std;

int n, sum, ans, a[110], b[110], f[110], g[110];
void up() {
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j <= i - 1; j++)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1); 
	}
}

void down() {
	g[1] = 1;
	for (int i = 2; i <= n; i++) {
		g[i] = 1;
		for (int j = 1; j <= i - 1; j++)
			if(b[i] > b[j]) g[i] = max(g[i], g[j] + 1); 
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[n - i + 1] = a[i];
	}
	up();
	down();
	for (int i = 1; i <= n / 2; i++)
		swap(g[i], g[n - i + 1]);
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i] + g[i] - 1);
	cout << n - ans << endl;
	return 0;
}
