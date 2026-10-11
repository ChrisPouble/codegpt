#include <bits/stdc++.h>
#define maxn 300010
using namespace std;

int cnt;
string ttttt; 
char s[maxn];
struct node {
	int l, r;
} a[maxn];

signed main() {
	cin >> ttttt;
	int len = ttttt.size();
	for (int i = len; i >= 1; i--) s[i] = ttttt[i - 1];
	for (int i = len; i >= 1; i--) {
		if(s[i] != 'A' || i == 1) continue;
		int top = i;
		while(s[top - 1] == 'W') top--;
		if(top < i) a[++cnt] = {top, i};
		if(top > 1) top--;
		while(top >= 1 && s[top] != 'A') top--;
		i = top + 1;
	}
	for (int i = 1; i <= cnt; i++) {
		int l = a[i].l, r = a[i].r;
		for (int k = l + 1; k <= r; k++) s[k] = 'C';
		s[l] = 'A';
	}
	for (int i = 1; i <= len; i++) cout << s[i];
	return 0;
}
