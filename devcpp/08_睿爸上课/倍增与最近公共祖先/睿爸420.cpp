#include <bits/stdc++.h>
using namespace std;

int n, q, father[10010], dep[10010];
vector<int>linker[10010];
void dfs(int x) {
	if(father[x] == -1) dep[x] = 1;
	else dep[x] = dep[father[x]] + 1;
	for (auto i:linker[x]) dfs(i);
}

int LCA(int x, int y) {
	int ans = 0x3f3f3f3f; 
	if(dep[x] < dep[y]) swap(x, y);
	int k = 0; //枚举最大能跳多少
	while((1 << (k + 1)) <= dep[x]) k++; //还能跳就接着跳 
	for (int i = k; i >= 0; i--)
		if(dep[father[x][i]] >= dep[y]) {
			ans = min(ans, dis[x]);
			x = father[x][i]; //让x和y处于同一高度 
		}
	for (int i = k; i >= 0; i--) //枚举向上条多少 
		if(father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
			ans = min(ans, dis[x]);
			ans = min(ans, dis[y]);
		}
	return ans;
}

int main() {
	cin >> n;
	memset(father, -1, sizeof(father));
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		father[b] = a;
		linker[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if(father[i] == -1) {
			dfs(i);
			break;
		}
	for (int j = 1; (1 << j) <= n; j++) //枚举向上跳几步 
		for (int i = 1; i <= n; i++) { //找出所有的点 
			father[i][j] = father[father[i][j - 1]][j - 1]; //先跳2^(j-1)步，再跳2^(j-1)步就可以了 
			dis[i][j] = dis[father[i][j - 1]][j - 1];
		}
	cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;
		cout << LCA(x, y) << endl; 
	}
    return 0;
}
