#include <bits/stdc++.h>
#define maxn 1010
#define int long long
using namespace std;

int n, ans, a[maxn], f[maxn];
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		f[i] = a[i];
		for (int j = 1; j < i; j++)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + a[i]);
	}
	for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}
