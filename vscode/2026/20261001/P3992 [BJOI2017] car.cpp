#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; 
	
	vector <int> a(n + 1), b(n + 1), car(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		car[i] = a[i];
	}

	for (int i = 1; i <= n; i++)
		cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int q; cin >> q;
	for (int pro = 0; pro <= q; pro++) {
		if (pro == 0) goto to;

		int id, x; cin >> id >> x;
		a.erase(lower_bound(a.begin(), a.end(), car[id])); car[id] = x;
		a.insert(lower_bound(a.begin(), a.end(), car[id]), x);

		to:

		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans += abs(a[i] - b[i]);
		cout << ans << endl;
	}
	return 0;
}