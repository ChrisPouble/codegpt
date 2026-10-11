#include <bits/stdc++.h>
#define maxn 300010
using namespace std;

int n;
map<int, int>t;
struct node {
	int val, id;
} a[maxn];

bool cmp(node x, node y) {
	return x.val < y.val;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].id = i, t[a[i].val]++;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = n; i >= 1; i--)
		if(t[a[i].val] == 1) {
			cout << a[i].id << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}
