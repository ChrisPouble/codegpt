#include <bits/stdc++.h>
using namespace std;

int n, m, ans, f[110][1010]; //f[i][j]表示前i种草药，时间为j时，可以获得的最大利益 
struct node {
	int t, w;
}a[110];

void dfs(int x, int t, int w) {
	if(f[x][t] > w) return ; //记忆化 
	if(x > m) {
		ans = max(w, ans);
		return ;
	}
	f[x][t] = w; //进行记录 
	if(t + a[x].t <= n) dfs(x + 1, t + a[x].t, w + a[x].w); //选 
	dfs(x + 1, t, w); //不选 
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> a[i].t >> a[i].w;
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
