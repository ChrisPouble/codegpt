#include <bits/stdc++.h>
using namespace std;

int ans;
string s;
signed main() {
	getline(cin, s); //读入字符串
	for (int i = 0; i < s.size(); i++)
		if(s[i] != ' ' && s[i] != '\n') ans++; //如果非空格和换行，则ans+1 
	cout << ans << endl;
	return 0;
}
