#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 10;

int n, a[N];
ll work(ll x) { return x * x; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	ll res = work(a[1] - a[2]) + work(a[n] - a[n - 1]);
	for (int i = 3; i <= n; i += 2)
		res += work(a[i] - a[i - 2]);
	
	for (int i = n - (n & 1); i >= 3; i -= 2)
		res += work(a[i] - a[i - 2]);
	
	ll ans = work(a[1] - a[n]);
	for (int i = 2; i <= n; i++)
		ans += work(a[i] - a[i - 1]);
	
	cout << min(res, ans) << endl;
	
	return 0;
}