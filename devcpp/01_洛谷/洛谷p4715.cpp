#include <bits/stdc++.h>
using namespace std;

int n;
struct node{
	int sl, id;
}a[260];

void dfs(int x) {
	if(x >= (1 << n)) return;
	else cout << x << endl; 
	dfs(x * 2);
	dfs(x * 2 + 1);
	a[x].sl = a[x * 2].sl > a[x * 2 + 1].sl ? a[x * 2].sl : a[x * 2 + 1].sl;
	a[x].id = a[x * 2].sl > a[x * 2 + 1].sl ? a[x * 2].id : a[x * 2 + 1].id;
	return;
}

int main() {
	cin >> n;
	int t = 1 << n;
	for (int i = 0; i < t; i++) {
		cin >> a[i + t].sl;
		a[i + t].id = i + 1;
	}
	dfs(1);
	int ans = a[2].sl > a[3].sl ? a[3].id : a[2].id;
	cout << ans << endl;
	return 0;
}
