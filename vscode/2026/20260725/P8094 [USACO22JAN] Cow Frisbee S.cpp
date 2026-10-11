#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 10;

int n, h[N], ans;
int top, sum[N], stap[N];

int get(int x) {
	int l = 1, r = top, res = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (h[stap[mid]] > h[x]) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	return res;
}

void add(int x) {
	// while (top >= 1 && h[stap[top]] < h[x]) top--;
	
	// int res = get(x);
	// if (res) ans += (top - res + 1) * (x + 1) - (sum[top] - sum[res - 1]);
	// stap[++top] = x, sum[top] = sum[top - 1] + x;

    while (top >= 1 && h[stap[top]] < h[x]) top--;

    if (top) ans += (x - stap[top] + 1);
    stap[++top] = x;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	
	top = 0;
	for (int i = 1; i <= n; i++)
		add(i);

	for (int i = 1; i <= n / 2; i++)
		swap(h[i], h[n - i + 1]);
	
	top = 0;
	for (int i = 1; i <= n; i++)
		add(i);
	
	cout << ans << endl; 
	return 0;
}