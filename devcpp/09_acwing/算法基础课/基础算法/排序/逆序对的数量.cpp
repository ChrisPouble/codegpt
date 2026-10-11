#include <bits/stdc++.h>
#define maxn 100010
#define int long long 
using namespace std;

int n, ans, a[maxn], t[maxn];
void merge_sort(int l, int r) {
	if(l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(l, mid);
	merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = l - 1;
	while(i <= mid && j <= r) {
		if(a[i] <= a[j]) t[++k] = a[i++];
		else t[++k] = a[j++], ans += mid - i + 1;
	}
	while(i <= mid) t[++k] = a[i++];
	while(j <= r) t[++k] = a[j++];
	for (int x = l; x <= r; x++) a[x] = t[x];
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	merge_sort(1, n);
	cout << ans << endl;
	return 0;
}
