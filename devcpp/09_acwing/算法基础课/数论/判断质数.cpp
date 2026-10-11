#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n;
bool is(int x) {
	if(x < 2) return false;
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

signed main() {
	cin >> n;
	while(n--) {
		int x;
		cin >> x;
		if(is(x)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
