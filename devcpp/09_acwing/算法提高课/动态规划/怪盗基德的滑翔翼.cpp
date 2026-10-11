#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int K, n, ans, h[maxn], f[maxn], g[maxn];
void solve() {
    cin >> n;
    ans = 0;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if(h[i] > h[j]) f[i] = max(f[i], f[j] + 1);
	}
	for (int i = 1; i <= n; i++) {
		g[i] = 1;
		for (int j = 1; j < i; j++)
			if(h[i] < h[j]) g[i] = max(g[i], g[j] + 1);
	}
	for (int i = 1; i <= n; i++) ans = max(ans, f[i]), ans = max(ans, g[i]);
	cout << ans << endl;
}

signed main() {
    cin >> K;
    while(K--) solve();
	return 0;
}
