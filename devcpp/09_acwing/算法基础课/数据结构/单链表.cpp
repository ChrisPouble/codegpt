#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int m, head, cnt, e[maxn], ne[maxn];
void init() {
	head = -1, cnt = 0;
}

void add_to_head(int x) {
	ne[++cnt] = head; //新节点的下一个节点是头节点 
	e[cnt] = x; //新节点的值 
	head = cnt; //更换头节点 
}

void add(int k, int x) {
	ne[++cnt] = ne[k]; //新节点的下一个节点是k的下一个节点 
	ne[k] = cnt; //更新k的下一个节点 
	e[cnt] = x; //更新节点的值 
}

void erase(int k) {
	if(k == 0) head = ne[head]; //删除头节点 
	else ne[k] = ne[ne[k]]; //更新下一个点 
}

signed main() {
	cin >> m, init();
	while(m--) {
		char op;
		int k, x;
		cin >> op;
		if(op == 'H') cin >> x, add_to_head(x);
		else if(op == 'D') cin >> k, erase(k);
		else cin >> k >> x, add(k, x);
	}
	for (int i = head; i != -1; i = ne[i]) cout << e[i] << " ";
	return 0;
}
