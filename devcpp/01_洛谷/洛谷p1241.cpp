#include <bits/stdc++.h>
using namespace std;

stack<char>st;
char is(char c) {
	if(c == '(') return ')';
	if(c == '[') return ']';
	return '}';
}

int main() {
	string s, ans = ""; cin >> s;
	for (int i = 0; i < s.size(); i++)
		st.push(s[i]);
	while(!st.empty()) {
		char x = st.top(); st.pop();
		if(st.empty()) {
			if(x == '(' || x == ')') {
				ans.insert(0, "(");
				ans.insert(1, ")");
			}
			if(x == '[' || x == ']') {
				ans.insert(0, "[");
				ans.insert(1, "]");
			}
		} else {
			char y = st.top();
			if(x == ')') {
				if(y == '(') st.pop();
				ans.insert(0, "(");
				ans.insert(1, ")");
			} else if(x == ']') {
				if(y == '[') st.pop();
				ans.insert(0, "[");
				ans.insert(1, "]");
			} else if(x == '(') {
				ans.insert(0, "(");
				ans.insert(1, ")");
			} else if(x == '[') {
				ans.insert(0, "[");
				ans.insert(1, "]");
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
