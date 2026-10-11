#include <bits/stdc++.h>
using namespace std;

set<int> s;
int main() {
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		for (int i = 1; i * i <= n; i++) { //别问，问就是自己想为什么是sqrt(n) 
			s.insert(n / i); //加上n / i
			s.insert(i); //加上i 
		}
		s.insert(0);
		cout << s.size() << endl;
		for (set<int>::iterator it = s.begin(); it != s.end(); it++)
			cout << *it << " ";
		cout << endl;
		s.clear();
	}
	return 0;
}
/*
10
24
25
29
30
99
100
109
110
224
225
*/