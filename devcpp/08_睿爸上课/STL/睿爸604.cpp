#include <bits/stdc++.h>
using namespace std;

int n, x;
string t;
multiset<int>s;
map<int, bool>vis;
int main() {
	cin >> n;
	while(n--) {
		cin >> t >> x;
		if(t == "add") {
			vis[x] = 1;
			s.insert(x);
			cout << s.count(x) << endl;
		} else if(t == "del") {
			cout << s.count(x) << endl;
			s.erase(x);
		} else {
			if(!vis[x]) cout << 0;
			else cout << 1;
			cout << " " << s.count(x) << endl;
		}
	}
	return 0;
}
