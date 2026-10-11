#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

inline int read() { //快读 
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

inline void write(int x) { //快写 
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int n, ans, siz[maxn]; //siz[i]表示下标为i的子树的大小 
struct node {
	int val, left, right;
}a[maxn]; //记录一个节点的权值，左右子树的下标 

inline bool work(int l, int r) {
	if(l == -1 && r == -1) return 1; //如果都搜到了空节点，则返回true 
	if(l == -1 || r == -1) return 0; //如果有一个搜到了空节点，则返回false 
	if(a[l].val != a[r].val) return 0; //如果权值不相等，则返回false
	return work(a[l].left, a[r].right) && work(a[l].right, a[r].left); //递归判断左右子树是否相等 
}

inline int dfs(int x) { //用来计算子树大小 
	return x == -1 ? 0 : siz[x] = dfs(a[x].left) + dfs(a[x].right) + 1; //如果搜到空节点，则大小为0；否则接着往下搜 
}

signed main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i].val = read();
	for (int i = 1; i <= n; i++) a[i].left = read(), a[i].right = read();
	dfs(1); //先预处理 
	for (int i = 1; i <= n; i++) if(work(i, i)) ans = ans > siz[i] ? ans : siz[i]; //如果发现可以更新，则更新 
	write(ans);
	return 0;
}
