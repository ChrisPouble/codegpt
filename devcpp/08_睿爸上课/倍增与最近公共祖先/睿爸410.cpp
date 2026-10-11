#include <bits/stdc++.h>
using namespace std;

int m, n, a[100010], f[100010][30]; //f[i][j]从i下标开始的连续2^j个区间里的最小值 
vector<int>vec; 
int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		f[i][0] = a[i]; //初始化 
	for (int j = 1; (1 << j) <= m; j++)
		for (int i = 1; i + (1 << j) - 1 <= m; i++)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]); //状态转移方程 
	while(n--) {
		int l, r;
		cin >> l >> r;
		int len = log2(r - l + 1); //求长度
		vec.push_back(min(f[l][len], f[r - (1 << len) + 1][len])); //最后的结果 
	}
	for (auto i:vec) cout << i << " ";
	return 0;
}
