#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int m, top, stac[maxn];
void init() {
	top = 0;
}

void push(int x) {
	stac[++top] = x;
}

void pop() {
	top--;
}

bool empty() {
	return top == 0;
}

int query() {
	return stac[top];
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
