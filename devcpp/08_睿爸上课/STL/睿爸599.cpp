#include <bits/stdc++.h>
using namespace std;

int n, ans, a[100010];
map<int, int>mp;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a + 1, a + n + 1, greater<int>());
	for (int i = 1; i <= n; i++)
		if(mp[ans] < mp[a[i]]) ans = a[i];
	cout << ans << " " << mp[ans] << endl; 
	return 0;
}
