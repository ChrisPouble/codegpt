#include<bits/stdc++.h>
#define int long long
using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int n, m, l = 0, r = 1e9, ans, a[100010], b[100010];
bool find(int x) {
	int l = 1, r = m;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(b[mid] == x) return 1;
		else if(b[mid] > x) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

signed main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		b[i] = read();
	sort(b + 1, b + m + 1);
	for (int i = 1; i <= n; i++)
		if(find(a[i])) write(a[i]), printf(" ");
	return 0;
}
