#include <bits/stdc++.h>
using namespace std;

int n, m, sum;
bool a[60][60], vis[60], ans[60];
void hb() {
	for (int i = 1; i <= n; i++)
		ans[i] = vis[i];
}

void dfs(int x, int s) {
	if(x > n) {
		if(s > sum) {
			sum = s;
			hb();
		}
		return;
	}
	bool temp = true;
	for (int i = 1; i < x; i++) {
		if(vis[i] == true && a[i][x] == true) {
			temp = false;
			break;
		}
	}
	if(temp) {
		vis[x] = true;
		dfs(x + 1, s + 1);
		vis[x] = false;
	}
	dfs(x + 1, s);
}
 
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y;
		a[x][y] = a[y][x] = 1;
	}
	dfs(1, 0);
	cout << sum << endl;
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}
