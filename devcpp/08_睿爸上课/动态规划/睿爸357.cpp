#include<bits/stdc++.h>
using namespace std;

int n, k, sum, ans, t[510], p[510], f[100010];
int main() {
	cin >> k >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		sum += p[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = k; j >= 0; j--)
			if(j >= t[i]) f[j] = max(f[j], f[j - t[i]] + p[i]);
	cout << sum - f[k] << endl;
	return 0;
}
