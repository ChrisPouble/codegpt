#include <bits/stdc++.h>
using namespace std;

int n, a[110], sum[110], f[110][110]; //f[i][j]表示以i为区间起点，j为区间终点的最小愤怒值 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i]; //算出前缀和，后面要用 
	}
	for (int len = 2; len <= n; len++) { //枚举区间长度 
		for (int i = 1; i + len - 1 <= n; i++) { //枚举区间开头 
			int j = i + len - 1; //计算区间末尾 
			f[i][j] = 0x3f3f3f3f; //初始化 
			for (int k = 1; k <= len; k++) //枚举i分割的中间点 
				f[i][j] = min(f[i][j], f[i + 1][i + k - 1] //算出由i分割成两边的左边所有人的愤怒值，即为f[i + 1][i + k - 1] 
					 + a[i] * (k - 1) //i的愤怒值 
					 + f[i + k][j] + k * (sum[j] - sum[i + k - 1]));  //算出由i分割成两边的右边所有人的愤怒值，由于前面已经有了k个人了，所以它们的愤怒值要加上它们原来愤怒值*k 
		}
	}
	cout << f[1][n] << endl;
	return 0;
}
