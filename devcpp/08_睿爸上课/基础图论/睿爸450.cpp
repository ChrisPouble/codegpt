#include <bits/stdc++.h>
using namespace std;

int n, k, dis[310], l[310][310];
bool vis[310];
void prim() { //最小生成树
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	//请注意，这里不要打上dis[1] = 1，因为这里要从所有点都走一遍 
	for (int i = 1; i <= n - 1; i++) { //跑n遍
		int temp = INT_MAX, t = -1;
		for (int j = 1; j <= n; j++)
			if(!vis[j] && temp > dis[j]) { //找到最小值 
				temp = dis[j];
				t = j;
			}
		vis[t] = 1; //这个点被访问过了 
		for (int j = 1; j <= n; j++)
			if(!vis[j] && dis[j] > l[t][j] && l[t][j] != 0) //如果这个点没有被访问过，并且如果由t点把水引导过来花费更小，则选择 
				dis[j] = l[t][j];
	}
	for (int i = 1; i <= n; i++)
		ans += dis[i];
	cout << ans << endl;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> dis[i]; //先把所有的点都看成是买了水库 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> l[i][j];
	prim();
}

int main() {
	cin >> k;
	while(k--) solve();
	return 0;
}
