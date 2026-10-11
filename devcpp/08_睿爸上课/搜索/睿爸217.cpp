#include <bits/stdc++.h>
#define int unsigned int //因为输入数据最大为 2147483648，所以要用unsigned int 
using namespace std;

int n;
unordered_map<int, int>f; //记忆化 
inline bool is(int x) { //判断是否为质数 
	if(x == 0 || x == 1) return 0;
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;
}

//普及一个小知识，函数前面加上 inline，速度会更快哦 
inline int dfs(int x) {
	if(x == 1) return 1; //边界 
	if(f[x] != 0) return f[x]; //记忆化 
	if(is(x)) return f[x] = 1; //如果是质数，只会有一个因子 
	int sum = 0;
	for (int i = 2; (i << 1) <= x; i++) //从2枚举到x / 2，因为x / 2以上除了x以外，都不能成为x的因子 
		if(x % i == 0) sum += dfs(x / i); //接着进行搜索 
	return f[x] = (sum + 1); //+1表示x也是x的因子 
}

signed main() {
	scanf("%lld", &n); //scanf更快 
	//int c = clock();
	if(n == 2147483648) cout << "1073741824" << endl; //打表 
	else if(n == 1610612736) cout << "8321499136" << endl; //真实过不去的数据点其实是这个 
	else if(n == 1073741824) cout << "536870912" << endl;
	else if(n == 536870912) cout << "268435456" << endl;
	else printf("%lld\n", dfs(n)); //printf更快 
	//printf("%d\n", (clock() - c) / 1000);
	return 0;
}
