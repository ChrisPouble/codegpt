#include <bits/stdc++.h>
using namespace std;

int n;
vector<int>ans;
int main() {
	cin >> n;
	if(n & 1) { //如果是奇数
		cout << "-1" << endl; //则输出-1 
		return 0;
	}
	while(n) {
		int k = (int)log2(n); //否则取出log2(n) 
		ans.push_back(1 << k); //答案里面加入log2(n) 
		n -= (1 << k); //并且n要减去2^k
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " "; //输出 
	return 0;
}
