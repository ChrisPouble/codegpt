#include <bits/stdc++.h>
#define int long long //请注意：十年OI一场空，不开long long见祖宗 
using namespace std;

int n, m, sx, sy, ex, ey, f[55][55]; //f[i][j]表示走到第i行，第j列的方案总数 
int work(int i, int j) { //写成函数更清晰 
	int sum = 0;
	if(i - 2 >= 1 && j - 1 >= 1) sum += f[i - 2][j - 1]; //判断 
	if(i - 2 >= 1 && j + 1 <= m) sum += f[i - 2][j + 1]; //各种
	if(i - 1 >= 1 && j - 2 >= 1) sum += f[i - 1][j - 2]; //越界 
	if(i - 1 >= 1 && j + 2 <= m) sum += f[i - 1][j + 2]; //问题 
	return sum; //返回 
}

signed main() {
	cin >> n >> m >> sx >> sy >> ex >> ey;
	f[sx][sy] = 1; //初始化 
	for (int i = sx + 1; i <= ex; i++) //从sx+1开始跑 
		for (int j = 1; j <= m; j++)
			f[i][j] = work(i, j);
	cout << f[ex][ey] << endl;
    return 0;
}
