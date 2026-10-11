#include <bits/stdc++.h>
using namespace std;

int n;
struct node{
	int left, right; 
}a[1000010];

int dfs(int x) {
	if(!x) return 0;
	return max(dfs(a[x].left), dfs(a[x].right)) + 1;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int l, r; cin >> l >> r;
		a[i].left = l, a[i].right = r;
	}
	cout << dfs(1) << endl;
	return 0;
}
