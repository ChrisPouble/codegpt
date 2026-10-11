#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int m, l, r, que[maxn];
void init() {
	l = 1, r = 0;
}

void push(int x) {
	que[++r] = x;
}

void pop() {
	l++;
}

bool empty() {
	return l > r;
}

int query() {
	return que[l];
}

signed main() {
	cin >> m, init();
	while(m--) {
		int x;
		string op;
		cin >> op;
		if(op == "push") cin >> x, push(x);
		else if(op == "pop") pop();
		else if(op == "empty") cout << (empty() ? "YES" : "NO") << endl;
		else cout << query() << endl;
	}
	return 0;
}
