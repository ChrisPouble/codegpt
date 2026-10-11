#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, ans, h[maxn], f[maxn][2];
signed main() {
    cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) {
		f[i][0] = f[i][1] = 1;
		for (int j = 1; j < i; j++)
			if(h[i] > h[j]) f[i][0] = max(f[i][0], f[j][0] + 1);
			else if(h[i] < h[j]) f[i][1] = max(f[i][1], max(f[j][0], f[j][1]) + 1);
	}
	for (int i = 1; i <= n; i++) ans = max(ans, f[i][0]), ans = max(ans, f[i][1]);
	cout << ans << endl;
	return 0;
}
