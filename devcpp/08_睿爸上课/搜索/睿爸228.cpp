#include <bits/stdc++.h>
using namespace std;

int n, r;
bool vis[25]; //vis[i]表示i这个数有没有访问过 
vector<int>now; //答案数组 
void dfs() {
	if(now.size() == r) { //如果满足条件 
		for (auto i:now) cout << i << " "; //输出答案 
		cout << endl; //换行 
		return;
	}
	for (int i = 1; i <= n; i++)
		if(!vis[i]) { //如果这个数没有被访问过 
			vis[i] = 1; //则记录 
			now.push_back(i); //并加入答案数组里 
			dfs(); //接着找 
			now.pop_back(); //回复现场，即回溯 
			vis[i] = 0;
		}
}

int main() {
	cin >> n >> r;
	dfs();
	return 0;
}
