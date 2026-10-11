#include <bits/stdc++.h>
using namespace std;

int n, k, ans = 1e9, f[110][110]; //f[i][j]表示前i本书，取出j本，所对应的最小不整齐度 
struct node {
	int g, k;
}a[110];

bool cmp(node x, node y) {
	return x.g < y.g;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i].g >> a[i].k;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 2; i <= n; i++)
		for (int j = 0; j <= k; j++)
			f[i][j] = 1e9; //初始化 
	for (int i = 2; i <= n; i++) {
		f[i][0] = f[i - 1][0] + abs(a[i].k - a[i - 1].k); //这里都能理解
		f[i][i - 1] = 0;
		for (int l = 1; l < i; l++) //l表示1~i-1的某一个位置，l与i之间的部分都不选 
			for (int j = 0; j <= l && j <= k; j++) //j表示l之前有多少本书不选 
				f[i][j + (i - l - 1)] = min(f[i][j + (i - l - 1)], f[l][j] + abs(a[i].k - a[l].k));
				/*
				f[i][j + (i - l - 1)] = min(f[i][j + (i - l - 1)], f[l][j] + abs(a[i].k - a[l].k));
				这个距离等于f[l][j](即l前j本书不选)的值+a[i].k-a[l].k(因为i和l之间没有书) 
				*/ 
	}
	for (int i = 1; i <= n; i++) //最后再求最小值 
		if(k - n + i >= 0) ans = min(ans, f[i][k - n + i]); 
	cout << ans << endl;
	return 0;
}
