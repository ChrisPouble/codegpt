#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int a[maxn], b[maxn], c[maxn];
string s, t;
int main() {
	cin >> s >> t;
	for (int i = 1; i <= s.size(); i++)
		a[i] = s[s.size() - i] - 48;
	for (int i = 1; i <= t.size(); i++)
		b[i] = t[t.size() - i] - 48;
	for (int i = 1; i <= max(s.size(), t.size()); i++) {
		if(a[i] < b[i]) a[i + 1]--, a[i] += 10;
		c[i] = a[i] - b[i];
	}
	int i = max(s.size(), t.size()); 
	while(c[i] == 0 && i > 1) i--;
	while(i) cout << c[i--];
	return 0;
}
