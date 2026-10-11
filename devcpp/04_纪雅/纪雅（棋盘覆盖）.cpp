#include <bits/stdc++.h>
using namespace std;

int t = 0, a[2000][2000];
void dfs(int x, int y, int p, int q, int n) { //x, y表示左上角所在位置，p，q表示已被赋值点的位置，n表示边长 
	if(n == 2) { //如果边长是2 
		t++;
		if(x != p || y != q) a[x][y] = t; //如果左上角没被赋值，就赋值为t 
		if(x + 1 != p || y != q) a[x + 1][y] = t; //如果左下角没被赋值，就赋值为t 
		if(x != p || y + 1 != q) a[x][y + 1] = t; //如果右上角没被赋值，就赋值为t 
		if(x + 1 != p || y + 1 != q) a[x + 1][y + 1] = t; //如果右下角没被赋值，就赋值为t 
		return;
	}
	if(p <= x + n / 2 - 1 && q <= y + n / 2 - 1) { //已被赋值的点在左上角 
		t++;
		//a b c d
		//e f g h
		//i j k l
		//m n o p 
		a[x + n / 2 - 1][y + n / 2] = t; //如上图，把g点赋值t 
		a[x + n / 2][y + n / 2 - 1] = t; //如上图，把j点赋值t 
		a[x + n / 2][y + n / 2] = t; //如上图，把k点赋值t 
		dfs(x, y, p, q, n / 2); //遍历左上角 
		dfs(x, y + n / 2, x + n / 2 - 1, y + n / 2, n / 2); //遍历右上角 
		dfs(x + n / 2, y, x + n / 2, y + n / 2 - 1, n / 2); //遍历左下角 
		dfs(x + n / 2, y + n / 2, x + n / 2, y + n / 2, n / 2); //遍历右下角 
	}
	if(p <= x + n / 2 - 1 && q >= y + n / 2) { //已被赋值的点在右上角 
		t++;
		//a b c d
		//e f g h
		//i j k l
		//m n o p 
		a[x + n / 2 - 1][y + n / 2 - 1] = t; //如上图，把f点赋值t 
		a[x + n / 2][y + n / 2 - 1] = t; //如上图，把j点赋值t
		a[x + n / 2][y + n / 2] = t; //如上图，把k点赋值t
		dfs(x, y, x + n / 2 - 1, y + n / 2 - 1, n / 2); //遍历左上角
		dfs(x, y + n / 2, p, q, n / 2); //遍历右上角
		dfs(x + n / 2, y, x + n / 2, y + n / 2 - 1, n / 2); //遍历左下角
		dfs(x + n / 2, y + n / 2, x + n / 2, y + n / 2, n / 2); //遍历右下角
	}
	if(p >= x + n / 2 && q <= y + n / 2 - 1) { //已被赋值的点在左上角 
		t++;
		//a b c d
		//e f g h
		//i j k l
		//m n o p 
		a[x + n / 2 - 1][y + n / 2 - 1] = t; //如上图，把f点赋值t
		a[x + n / 2 - 1][y + n / 2] = t; //如上图，把g点赋值t
		a[x + n / 2][y + n / 2] = t; //如上图，把k点赋值t
		dfs(x, y, x + n / 2 - 1, y + n / 2 - 1, n / 2); //遍历左上角
		dfs(x, y + n / 2, x + n / 2 - 1, y + n / 2, n / 2); //遍历右上角
		dfs(x + n / 2, y, p, q, n / 2); //遍历左下角
		dfs(x + n / 2, y + n / 2, x + n / 2, y + n / 2, n / 2); //遍历右下角
	}
	if(p >= x + n / 2 && q >= y + n / 2) { //已被赋值的点在右下角
		t++;
		//a b c d
		//e f g h
		//i j k l
		//m n o p
		a[x + n / 2 - 1][y + n / 2 - 1] = t; //如上图，把f点赋值t
		a[x + n / 2 - 1][y + n / 2] = t; //如上图，把g点赋值t
		a[x + n / 2][y + n / 2 - 1] = t; //如上图，把j点赋值t
		dfs(x, y, x + n / 2 - 1, y + n / 2 - 1, n / 2); //遍历左上角
		dfs(x, y + n / 2, x + n / 2 - 1, y + n / 2, n / 2); //遍历右上角
		dfs(x + n / 2, y, x + n / 2, y + n / 2 - 1, n / 2); //遍历左下角
		dfs(x + n / 2, y + n / 2, p, q, n / 2); //遍历右下角
	}
}

int main() {
	int n, x, y; cin >> n >> x >> y;
	a[x][y] = -1;
	dfs(1, 1, x, y, n);
	for (int i = 1; i <= n; i++, puts(" "))
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
	return 0;
}
