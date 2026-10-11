#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, a[maxn];
void qsort(int l, int r) {
	if(l >= r) return ;
	int i = l, j = r, mid = (l + r + 1) / 2, k = a[mid];
	while(i <= j) {
		while(a[i] < k) i++;
		while(a[j] > k) j--;
		if(i <= j) swap(a[i++], a[j--]);
	}
	if(i < r) qsort(i, r);
	if(j > l) qsort(l, j);
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	qsort(1, n);
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
	return 0;
}
