#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, a[maxn], b[maxn]; 
signed main() {
	cin >> n >> m;
	if(n > m) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	int l = 1, r = 1;
	while(l <= n && r <= m) {
		if(a[l] == b[r]) l++;
		r++;
	}
	if(l <= n) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}
