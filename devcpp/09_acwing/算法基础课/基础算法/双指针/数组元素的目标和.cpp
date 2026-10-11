#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, x, a[maxn], b[maxn];
int main() {
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	int l = 1, r = m;
	while(l <= n && r >= 1) {
		while(a[l] + b[r] > x && r >= 1) r--;
		if(r >= 1 && a[l] + b[r] == x) cout << l - 1 << " " << r - 1 << endl;
		l++;
	}
	return 0;
}
