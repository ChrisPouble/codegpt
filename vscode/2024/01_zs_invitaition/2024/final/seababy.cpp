#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k, m, ans = 0; cin >> n >> k >> m;
	while(n < m) {
		ans++;
		n = n + n * k;
	}
	cout << ans << endl;
	return 0;
}
