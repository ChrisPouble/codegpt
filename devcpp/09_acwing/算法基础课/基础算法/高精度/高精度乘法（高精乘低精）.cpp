#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int t, a[maxn], c[maxn];
string s;
int main() {
	cin >> s >> t;
	for (int i = 1; i <= s.size(); i++)
		a[i] = s[s.size() - i] - 48;
	for (int i = 1; i <= s.size() + 10; i++) {
		c[i] += a[i] * t;
		c[i + 1] += c[i] / 10;
		c[i] %= 10;
	}
	int i = s.size() + 10; 
	while(c[i] == 0 && i > 1) i--;
	while(i) cout << c[i--];
	return 0;
}
