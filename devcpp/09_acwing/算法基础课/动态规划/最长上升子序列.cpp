#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, ans, a[maxn], f[maxn];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
	}
	for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}
