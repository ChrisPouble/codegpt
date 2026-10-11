#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n;
multiset <int> arc;
string s;

int main() {
	cin >> n >> s;

	for (int i = 1; i < s.size() - 1; i++) {
		if (s[i] == 'R') {
			int k = 0, l = i - 1, r = i + 1;
			while (l >= 0 && r < s.size() && s[l] == 'A' && s[r] == 'C') {
				k++;
				l--, r++;
			}
			
            if (k) arc.insert(k);
		}
	}

	int ans = 0;
	while (arc.size()) {
		ans++;
		if (ans % 2 == 0) {
			arc.erase(arc.begin());
		} else {
			auto it = arc.end(); it--;
			
            int x = *it;
			arc.erase(it);
			if (--x) arc.insert(x);
		}
	}

	cout << ans << "\n";
	return 0;
}