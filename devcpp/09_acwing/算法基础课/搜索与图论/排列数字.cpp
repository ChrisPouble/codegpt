#include <bits/stdc++.h>
using namespace std;

int n, vis[10], ans[10]; 
void dfs(int x) {
	if(x == n + 1) {
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
		return ;
	}
	for (int i = 1; i <= n; i++)
		if(!vis[i]) vis[i] = 1, ans[x] = i, dfs(x + 1), vis[i] = 0;
}

signed main() {
	cin >> n;
	dfs(1);
	return 0;
}
