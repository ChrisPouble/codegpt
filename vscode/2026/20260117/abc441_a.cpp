#include <bits/stdc++.h>
#define int long long
using namespace std;

int p, q, x, y;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
    cin >> p >> q >> x >> y;

    if (p <= x && x <= p + 100 - 1 && q <= y && y <= q + 100 - 1) cout << "Yes\n";
    else cout << "No\n";

	return 0;
}