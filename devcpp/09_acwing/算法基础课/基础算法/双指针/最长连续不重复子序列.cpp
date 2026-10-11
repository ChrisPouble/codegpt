#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, l = 1, r = 1, ans, a[maxn];
bool vis[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	while(r <= n) {
		if(vis[a[r]] == 0) vis[a[r++]] = 1;
		else {
			while(vis[a[r]] == 1) vis[a[l++]] = 0;
			vis[a[r++]] = 1;
		}
		ans = max(ans, r - l);
	}
	cout << ans << endl;
	return 0;
}
