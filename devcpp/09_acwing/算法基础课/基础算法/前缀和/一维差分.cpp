#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, q, s[maxn], a[maxn];
void insert(int l, int r, int c) {
	s[l] += c;
	s[r + 1] -= c;
} 

int main() { 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) s[i] = a[i] - a[i - 1];
	while(q--) {
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for (int i = 1; i <= n; i++) s[i] += s[i - 1];
	for (int i = 1; i <= n; i++) cout << s[i] << " ";
	return 0;
}
