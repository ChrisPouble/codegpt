#include <bits/stdc++.h>
using namespace std;

int n, m, x;
set<int>s;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n + m; i++) { //哈哈，想不到我会这么输入吧! 
		cin >> x;
		s.insert(x); //加入元素 
	}
	for (auto i:s) cout << i << " "; //输出 
	return 0;
}
