#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, ans, a[maxn], f[maxn], g[maxn];
void up() {
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1); 
	}
}

void down() {
	for (int i = n; i >= 1; i--) {
		g[i] = 1;
		for (int j = i + 1; j <= n; j++)
			if(a[i] > a[j]) g[i] = max(g[i], g[j] + 1); 
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	up(), down();
	for (int i = 1; i <= n; i++) ans = max(ans, f[i] + g[i] - 1);
	cout << n - ans << endl;
	return 0;
}
