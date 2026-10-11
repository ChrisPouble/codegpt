#include <bits/stdc++.h>
using namespace std;

int k, m;
string n;
long long sum;
stack<char>st;
int jz1(char c) {
	if(c >= '0' && c <= '9') return c - 48;
	return c - 55;
}

char jz2(int d) {
	if(d >= 0 && d <= 9) return d + 48;
	return d + 55;
}

int main() {
	cin >> k >> n >> m;
	int cnt = 0;
	for (int i = n.size() - 1; i >= 0; i--)
		sum += jz1(n[i]) * pow(k, cnt++);
	while(sum) {
		st.push(jz2(sum % m));
		sum /= m;
	}
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
