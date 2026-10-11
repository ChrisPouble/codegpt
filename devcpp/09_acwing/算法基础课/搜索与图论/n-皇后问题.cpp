#include <bits/stdc++.h>
using namespace std;

int n, ans[10]; 
bool vis1[30], vis2[30], vis3[30]; //i¡¢x + i¡¢i - x + n 
void dfs(int x) {
	if(x == n + 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < ans[i]; j++) cout << ".";
			cout << "Q";
			for (int k = ans[i] + 1; k <= n; k++) cout << ".";
			cout << endl;
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(!vis1[i] && !vis2[i + x] && !vis3[i - x + n]) {
			vis1[i] = 1, vis2[i + x] = 1, vis3[i - x + n] = 1, ans[x] = i;
			dfs(x + 1);
			vis1[i] = 0, vis2[i + x] = 0, vis3[i - x + n] = 0;
		}
	}
}

signed main() {
	cin >> n;
	dfs(1);
	return 0;
}
