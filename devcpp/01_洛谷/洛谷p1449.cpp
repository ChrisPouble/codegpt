#include <bits/stdc++.h>
using namespace std;

stack<int>st;
int num;
int main() {
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if(s[i] == '@') break;
		if(s[i] >= '0' && s[i] <= '9') num = num * 10 + (s[i] - 48);
		else if(s[i] == '.') st.push(num), num = 0;
		else{
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			if(s[i] == '+') st.push(y + x);
			if(s[i] == '-') st.push(y - x);
			if(s[i] == '*') st.push(y * x);
			if(s[i] == '/') st.push(y / x);
		}
	}
	cout << st.top() << endl; 
	return 0;
}
