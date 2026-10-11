#include <bits/stdc++.h>
using namespace std;
    
long long ans, a[200010];
int n, c, q;
map<int, int>m;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	m[a[i]] = i;
	}
	cin >> q;
	while(q--) {
		cin >> c;
		cout << m[c] << endl;
	}
    return 0;
}
