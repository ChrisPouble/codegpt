#include <bits/stdc++.h>
using namespace std;

int T, ans, opt, score;
string name;
map<string, int>m;
int main() {
	cin >> T;
	while(T--) {
		cin >> opt;
		if(opt == 1) {
			cin >> name >> score;
			if(!m[name]) ans++;
			m[name] = score;
			cout << "OK" << endl;
		} else if(opt == 2) {
			cin >> name;
			if(m[name]) cout << m[name] << endl;
			else cout << "Not found" << endl;
		} else if(opt == 3) {
			cin >> name;
			if(!m[name]) cout << "Not found" << endl;
			else {
				ans--;
				m[name] = 0;
				cout << "Deleted successfully" << endl;
			}
		} else cout << ans << endl;
	}
    return 0;
}
