#include <bits/stdc++.h>
using namespace std;

int n, ans, a[15][15], g[15][15], jyh[15][15]; //jyh数组用来给搜索时做记忆化搜索，可以节省大量时间 
bool vis[15][15];
int new_sum(int x, int y) {
	return a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x][y + 1] + a[x + 1][y + 1] + a[x + 2][y + 1] + a[x][y + 2] + a[x + 1][y + 2] + a[x + 2][y + 2];
}

bool is_vis(int i, int j) {
	return (!vis[i][j] && !vis[i + 1][j] && !vis[i + 2][j] && !vis[i][j + 1] && !vis[i + 1][j + 1] && !vis[i + 2][j + 1] && !vis[i][j + 2] && !vis[i + 1][j + 2] && !vis[i + 2][j + 2]);
}

int dfs(int x, int y) {
	if(x + 2 > n || y + 2 > n) return 0; //边界 
	if(jyh[x][y] != 0) return jyh[x][y]; //记忆化 
	int sum = 0;
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= n - 2; j++) {
			if((abs(x - i) >= 3 || abs(y - j) >= 3) && is_vis(i, j)) { //必须满足要求，不能重叠 
				vis[i][j] = vis[i + 1][j] = vis[i + 2][j] = vis[i][j + 1] = vis[i + 1][j + 1] = vis[i + 2][j + 1] = vis[i][j + 2] = vis[i + 1][j + 2] = vis[i + 2][j + 2] = true; 
				jyh[i][j] = dfs(i, j); //进行记录 
				sum = max(sum, jyh[i][j] + g[x][y]); //这里加上的是g[x][y]，不是g[i][j] 
				vis[i][j] = vis[i + 1][j] = vis[i + 2][j] = vis[i][j + 1] = vis[i + 1][j + 1] = vis[i + 2][j + 1] = vis[i][j + 2] = vis[i + 1][j + 2] = vis[i + 2][j + 2] = false;
			}
		}
	sum = max(sum, g[x][y]); //重点：在上面的循环中如果没进去，就要返回自己这个矩阵 
	return sum;
}

int main() {
	cin >> n;
	if(n <= 2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= n - 2; j++)
			g[i][j] = new_sum(i, j); //计算每一个矩阵的和 
	
	for (int i = 1; i <= n - 2; i++, puts(" "))
		for (int j = 1; j <= n - 2; j++)
			cout << g[i][j] << " ";
	
	int ans = -100000;
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= n - 2; j++) {
			vis[i][j] = vis[i + 1][j] = vis[i + 2][j] = vis[i][j + 1] = vis[i + 1][j + 1] = vis[i + 2][j + 1] = vis[i][j + 2] = vis[i + 1][j + 2] = vis[i + 2][j + 2] = true;
			ans = max(ans, dfs(i, j));
			vis[i][j] = vis[i + 1][j] = vis[i + 2][j] = vis[i][j + 1] = vis[i + 1][j + 1] = vis[i + 2][j + 1] = vis[i][j + 2] = vis[i + 1][j + 2] = vis[i + 2][j + 2] = false;
		}
	cout << ans << endl;
	return 0; 
}
/*
5
1 2 3 4 5
5 4 3 2 1
1 2 -9 4 5
1 2 3 4 5
5 4 3 2 1

6
1 2 3 4 5 6
5 4 3 2 1 6
1 2 -9 4 5 6
1 2 3 4 5 6
5 4 3 2 1 6
6 6 6 6 6 6

6
1 2 3 4 5 7
5 4 3 2 1 7
1 2 -9 4 5 7
1 2 3 4 5 7
5 4 3 2 1 7
7 7 7 7 7 7
*/
