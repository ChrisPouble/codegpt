#include <bits/stdc++.h>
using namespace std;
#define mod 23333

vector<string>linker[mod + 2]; //哈希表 
int n, ans;
string s;
void insert() {
	int Hash = 0;
	for (int i = 0; s[i]; i++) //计算哈希值 
		Hash = (Hash * 250 + s[i]) % mod;
	for (int i = 0; i < linker[Hash].size(); i++) //遍历 
		if(linker[Hash][i] == s) return; //如果有了，就返回 
	linker[Hash].push_back(s); //没有就添加进去 
	ans++; //答案增加 
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s, insert();
	cout << ans << endl;
    return 0;
}
