#include <bits/stdc++.h>
using namespace std;

int n, k;
int main() {
	cin >> n >> k; 
	if(n < k) {
		cout << 2 << endl;
		return 0;
	}
	if(n * 2 % k == 0) cout << n * 2 / k << endl;
	else cout << n * 2 / k + 1 << endl;
	return 0;
}
