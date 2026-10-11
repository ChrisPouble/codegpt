#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int ans = -1;
	for (int i = 0; i < s.size(); i++) {
		int sum = 0;
		for (int j = i; j < s.size(); j++)
			if(j == i || s[j] == s[j - 1]) sum++;
			else break;
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0; 
} 
