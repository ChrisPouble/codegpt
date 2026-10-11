#include <bits/stdc++.h>
using namespace std;

int n, ans, a[2010];
bool hash[100010];
int main() {
	cin >> n;
	vector<int>v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		hash[a[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if(hash[a[i] + a[j]] == false) {
				v.push_back(a[i] + a[j]);
				ans++;
				hash[a[i] + a[j]] = true;
			}
	sort(v.begin(), v.end());
	cout << ans << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	return 0; 
} 
