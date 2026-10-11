#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
bool vis[20];
vector<int>G[110];
int check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (auto j:G[i])
			if(vis[j]) sum++;
		if(sum == G[i].size()) cnt++;
	}
	return cnt;
}

void dfs(int id, int last) {
	if(id == m) {
		int sum = check();
		ans = max(ans, sum);
		return;
	}
	if(id > k) return;
	for (int i = last + 1; i <= k; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			dfs(id + 1, i);
			vis[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int len; cin >> len;
		for (int j = 1; j <= len; j++) {
			int t; cin >> t;
			G[i].push_back(t);
		}
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
