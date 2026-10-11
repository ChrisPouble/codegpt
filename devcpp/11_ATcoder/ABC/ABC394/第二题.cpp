#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n;
string s[maxn];
bool cmp(string s, string t) {
	return s.size() < t.size();
} 

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + n + 1, cmp);
	for (int i = 1; i <= n; i++) cout << s[i];
	return 0;
}
