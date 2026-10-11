#include <bits/stdc++.h>
using namespace std;

int n, d;
string s;
map<string, bool>vis;
int main() {
	cin >> n;
	while(n--) {
		cin >> d >> s;
		if(d == 0) {
			for (int i = 0; i < s.size(); i++)
				if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32; //换成小写字母 
			vis[s] = 1; //进行记录 
		} else {
			for (int i = 0; i < s.size(); i++)
				if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32; //换成小写字母 
			if(vis[s]) cout << "Yes" << endl; //如果学过，输出Yes 
			else cout << "No" << endl; //否则输出No 
		}
	}
	return 0;
}
