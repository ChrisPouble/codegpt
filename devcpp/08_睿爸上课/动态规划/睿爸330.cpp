#include <bits/stdc++.h>
using namespace std;

int n, m, a[110][110], f[110][110];
int dfs(int x, int y) {
	if(f[x][y] >= 0) return f[x][y];
	int res = a[x][y];
	for (int i = max(1, x - m); i <= min(n, x + m); i++) //不能越界
		//枚举所有的水平方向 
		if(a[i][y] > a[x][y]) res = max(res, dfs(i, y) + a[x][y]);
	for (int j = max(1, y - m); j <= min(n, y + m); j++) //不能越界 
		//枚举所有的垂直方向 
		if(a[x][j] > a[x][y]) res = max(res, dfs(x, j) + a[x][y]);
	return f[x][y] = res;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	memset(f, -1, sizeof(f));
	cout << dfs(1, 1) << endl;
	return 0;
}
