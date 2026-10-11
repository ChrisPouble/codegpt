#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k, a[MAXN];

bool check(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] / x;
		if (a[i] == x) cnt--;
	}
	return cnt <= k;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = 1e9;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
	return 0;
}