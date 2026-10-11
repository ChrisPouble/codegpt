#include <bits/stdc++.h>
using namespace std;

int ans;
string s;
signed main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) if(s[i] == '1') ans++; //¼ÇÂ¼´ð°¸ 
	cout << ans << endl;
	return 0;
}
