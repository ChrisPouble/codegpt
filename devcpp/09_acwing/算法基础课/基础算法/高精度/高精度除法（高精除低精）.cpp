#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int t, a[maxn], ans[maxn], d; //t表示除数，a表示被除数，ans表示商，d表示余数 
string s; //被除数
int main() {
	cin >> s >> t;
	for (int i = 1; i <= s.size(); i++) a[i] = s[i - 1] - 48;
	for (int i = 1; i <= s.size(); i++) {
		d = d * 10 + a[i];
		ans[i] = d / t;
		d %= t;
	}
	int i = 1;
	while(ans[i] == 0 && i < s.size()) i++;
	while(i <= s.size()) cout << ans[i++];
	cout << endl << d;
	return 0;
}
