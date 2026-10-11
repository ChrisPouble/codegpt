#include<bits/stdc++.h>
#define int long long
#define mp make_pair
using namespace std;

int n, r, c, x, y;
string s;
map<pair<int, int>, int> vis;
signed main() {
	cin >> n >> r >> c >> s;
	s = ' ' + s, x = 0, y = 0, vis[mp(x, y)] = 1;
	for (int i = 1; i <= n; i++) {
		if(s[i] == 'N') {
			r++, x++;
			vis[mp(x, y)] = 1;
		} else if(s[i] == 'S') {
			r--, x--;
			vis[mp(x, y)] = 1;
		} else if(s[i] == 'W') {
			c++, y++;
			vis[mp(x, y)] = 1;
		} else {
			c--, y--;
			vis[mp(x, y)] = 1;
		}
		cout << vis[mp(r, c)];
	}
	return 0;
}
