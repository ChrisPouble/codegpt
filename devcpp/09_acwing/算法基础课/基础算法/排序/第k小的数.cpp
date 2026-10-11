#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, k, a[maxn];
void qsort(int l, int r) {
	int i = l, j = r, pivot = a[(l + r + 1) / 2];
	while(i <= j) {
		while(a[i] < pivot) i++;
		while(a[j] > pivot) j--;
		if(i <= j) swap(a[i++], a[j--]);
	}
	if(k >= i) qsort(i, r);
	else if(k <= j) qsort(l, j);
	else return ;
}

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	qsort(1, n);
	cout << a[k] << endl;
	return 0;
}
