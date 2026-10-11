#include <bits/stdc++.h>
using namespace std;

int n;
char start;
struct node {
	int left, right;
	char val;
}ecs[140];

void dfs(int x) {
	bool t1 = true, t2 = true;
	if((char)ecs[x].left == '*') t1 = false;
	if((char)ecs[x].right == '*') t2 = false;
	cout << ecs[x].val;
	if((!t1) && (!t2)) return;
	if(t1) dfs(ecs[x].left);
	if(t2) dfs(ecs[x].right);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		if(i == 1) start = s[0];
		ecs[(int)s[0]].left = (int)s[1];
		ecs[(int)s[0]].right = (int)s[2];
		ecs[(int)s[0]].val = s[0];
	}
	dfs((int)start);
	return 0;
} 
