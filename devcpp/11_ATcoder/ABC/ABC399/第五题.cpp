#include <bits/stdc++.h>
#define maxn 130
using namespace std;

int n, ans;
string s, t; 
char to[maxn];
int in[maxn];
bool f[maxn];
queue<char> q;
signed main() {
	cin >> n >> s >> t;
	if(s == t) {
		cout << 0 << endl;
		return 0;
	}
	s = " " + s, t = " " + t;
	for (int i = 1; i <= n; i++) {
		if(to[s[i]]) {
			if(to[s[i]] != t[i]) { //多分支 
				cout << -1 << endl;
				return 0;
			}
		} else {
			to[s[i]] = t[i];
			in[t[i]]++; //入度++ 
		}
	}
	for (char c = 'a'; c <= 'z'; c++)
		if(in[(int)c] == 0) q.push(c);
	if(q.empty()) {
		cout << -1 << endl;
		return 0;
	}
	while(!q.empty()) {
		char x = q.front();
		q.pop();
		if(to[(int)x]) ans++;
		in[to[(int)x]]--;
		if(in[(int)to[(int)x]] == 0) q.push((int)to[(int)x]);
		else f[(int)to[(int)x]] = 1; //说明入度 > 1（杂环的汇入点） 
	}
	for (char c = 'a'; c <= 'z'; c++) {
		if(in[(int)c] == 0) continue; //不在环上 
		bool flag = 0;
		char pos = to[(int)c];
		if(c == pos) continue; //自环（不需要管） 
		while(in[(int)pos]) {
			ans++;
			in[pos]--;
			if(f[pos]) flag = 1;
			pos = to[(int)pos]; 
		}
		if(flag == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}
