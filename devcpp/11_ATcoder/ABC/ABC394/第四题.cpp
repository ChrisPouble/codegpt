#include <bits/stdc++.h>
using namespace std;

string s;
stack<char>st;
bool check(char c) {
	if(st.empty()) return 0;
	if(c == '>' && st.top() == '<') return 1;
	if(c == ')' && st.top() == '(') return 1;
	if(c == ']' && st.top() == '[') return 1;
	return 0;
}

signed main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if(c == '>' || c == ']' || c == ')') {
			if(check(c)) st.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
		} else st.push(c);
	}
	if(st.empty()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
