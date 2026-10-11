#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, ans, a[maxn];
multiset <int> s;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (s.find(a[i]) == s.end()) continue;

		auto x = s.lower_bound(a[i]);
		if (x == s.begin() || x == s.end()) continue;
		
		ans++; s.erase(--x);
	}
    
	cout << n - ans << endl;
	return 0;
}