#include <bits/stdc++.h>
using namespace std;

int x, k = 1, n, ans;
struct node {
	int last, lj;
}l[100010];

int main() {
	cin >> n >> x;
	l[1].last = x;
	l[1].lj = 1;
	for (int i = 1; i <= n - 1; i++) {
		cin >> x;
		int mint = 1;
		for (int i = 1; i <= k; i++)
			if(l[i].last >= x) mint = min(l[i].last, l[mint].last);
		if(mint == 50010) l[++k].last = l[mint].last, l[k].lj++;
		else l[mint].last = x, l[mint].lj++;
	}
	for (int i = 1; i <= k; i++)
		ans = max(ans, l[i].lj);
	cout << ans << endl;
	cout << k << endl;
	return 0;
}
