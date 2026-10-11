#include <bits/stdc++.h>
using namespace std;

int ans = 0x3f3f3f3f, a[5][5];
void yh(int x, int y) { //给四周包括自己进行按按钮操作 
	a[x][y] ^= 1;
	a[x + 1][y] ^= 1;
	a[x][y + 1] ^= 1;
	a[x - 1][y] ^= 1;
	a[x][y - 1] ^= 1;
}

void dfs(int x, int y, int temp_ans) { //x代表第x行，y代表第y列，temp_ans代表答案 
	if(y > 3) { //如果列数到头了 
		x++; //换到下一行 
		y = 1; //换到下一行的第一列 
	}
	if(x > 3) { //如果行数也到头了
		//判断是否满足题目要求 
		for (int i = 1; i <= 3; i++)
			for (int j = 1; j <= 3; j++)
				if(a[i][j] == 0) return;
		if(ans > temp_ans) {
			ans = temp_ans; //更新答案 
			return; //返回 
		}
	}
	yh(x, y); //四周及自己都进行按按钮操作 
	dfs(x, y + 1, temp_ans + 1); //如果选了这个点，接着dfs
	yh(x, y); //恢复现场 
	dfs(x, y + 1, temp_ans); //如果没选这个点，接着dfs
}

int main() {
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	dfs(1, 1, 0);
	cout << ans << endl;
	return 0;
}
