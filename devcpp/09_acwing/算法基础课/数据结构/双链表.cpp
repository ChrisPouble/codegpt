#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int m, cnt, e[maxn], l[maxn], r[maxn];
void init() {
	r[0] = 1, l[1] = 0, cnt = 2;
}

void add_right(int k, int x) { //第k个点的右边插入点x
	e[++cnt] = x; //新节点的值 
	r[cnt] = r[k];
	l[cnt] = k;
	l[r[k]] = cnt; 
	r[k] = cnt;
}

void add_left(int k, int x) { //第k个点的左边插入点x
	e[++cnt] = x; //新节点的值 
	l[cnt] = l[k];
	r[cnt] = k;
	r[l[k]] = cnt; 
	l[k] = cnt;
}

void erase(int k) {
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}

signed main() {
	cin >> m, init();
	while(m--) {
		string op;
		int k, x;
		cin >> op;
		if(op == "L") cin >> x, add_right(0, x);
		else if(op == "R") cin >> x, add_left(1, x);
		else if(op == "D") cin >> k, erase(k + 2); //由于0和1已经定义过了，所以要加上一个偏移量，下面同理 
		else if(op == "IL") cin >> k >> x, add_left(k + 2, x);
		else cin >> k >> x, add_right(k + 2, x);
	}
	for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
	return 0;
}
