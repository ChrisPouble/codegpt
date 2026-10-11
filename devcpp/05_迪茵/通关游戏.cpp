#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[200010];
struct node{
	int A, B, X;
}a[100010];

int dfs(int x) {
	if(x == n) return 0;
	if(vis[x]) return 100000000;
	vis[x] = 1;
	int t = min(dfs(x + 1) + a[x].A, dfs(a[x].X) + a[x].B);
	vis[x] = 0;
	return t;
}

int main() {
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> a[i].A >> a[i].B >> a[i].X;
	cout << dfs(1) << endl;
	return 0;
}
