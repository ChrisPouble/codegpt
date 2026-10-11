#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, q, fw[maxn * 2], a[maxn * 2], fan[maxn * 2];
string s;
stack<int>st; //栈用来建树
struct NODE {
	int l, r;
}node[maxn * 2];

int dfs(int x, int y) { //y表示x是否要取反
	a[x] ^= y; //取反，因为德·摩根定律
	if(x <= n) return a[x]; //叶节点，直接返回
	int l = dfs(node[x].l, fan[node[x].l] ^ y); //往下查找，注意要^y(德·摩根定律) 
	int r = dfs(node[x].r, fan[node[x].r] ^ y); //往下查找，注意要^y(德·摩根定律) 
	if(a[x] == 2) { //如果为&
		if(!l) fw[node[x].r] = 1; //废物标记 
		if(!r) fw[node[x].l] = 1;
		return l & r; //返回 
	}
	if(a[x] == 3) { //如果为|
		if(l) fw[node[x].r] = 1; //废物标记 
		if(r) fw[node[x].l] = 1;
		return l | r; //返回
	}
}

void dfs1(int x) { //每一个儿子都要进行废物标记
	if(x <= n) return;
	fw[node[x].l] |= fw[x], fw[node[x].r] |= fw[x]; //如果x是废物，则x的子孙后代都是废物 
	dfs1(node[x].l), dfs1(node[x].r); //接着往下进行废物标记 
}

int main() {
	getline(cin, s);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int sum = n, len = s.size(); //sum从n开始 
	for (int i = 0; i < len; i++) {
		if(s[i] == 'x') {
			int x = 0;
			while(s[++i] != ' ') x = x * 10 + (s[i] - '0'); //把下标输入 
			st.push(x);
		} else if(s[i] == '&') {
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			node[++sum].l = x, node[sum].r = y; //左右子树记录下来 
			st.push(sum), a[sum] = 2; //&表示2 
		} else if(s[i] == '|') {
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			node[++sum].l = x, node[sum].r = y; //左右子树记录下来
			st.push(sum), a[sum] = 3; //|表示3
		} else if(s[i] == '!') {
			int x = st.top();
			fan[x] = !fan[x]; //进行取反 
		}
	}
	int ans = dfs(sum, fan[sum]);
	dfs1(sum); 
	scanf("%d", &q);
	while(q--) {
		int k;
		scanf("%d", &k);
		printf("%d\n", fw[k] ? ans : !ans); //如果是废物，则输出ans，否则输出!ans 
	}
	return 0;
}
