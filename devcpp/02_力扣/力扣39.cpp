#include <bits/stdc++.h>

using namespace std;

//为什么要用dfs，因为要循环嵌套的层数是变量n
//1 .先假设不重复 下一轮i+1开始
//	总结：
//	1.1 搜索时 break、continue、return的区别
//  1.2 想明白递归其实是复制多个函数
//  1.3 为什么要push后 调用下一步搜索后要pop
//  问题
//  1.4  先做排序是否可以把continue改成return
//2. 可以重复
//  2.1 解决重复下一轮 i开始
int a[50], f[50], n, target;
void dfs(int start, int sum, vector<int> &state, vector<vector<int> > &res) {
	if(sum == 0) {
		res.push_back(state);
		return;
	} 
	for (int i = start; i <= n; i++) {
		if(a[i] > sum) continue;
		state.push_back(a[i]);
		dfs(i, sum - a[i], state, res);
		state.pop_back(); 
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> target;
	
 	vector<int> state;
 	vector<vector<int> > res;
	dfs(1, target, state, res);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
    }
	return 0;
}
