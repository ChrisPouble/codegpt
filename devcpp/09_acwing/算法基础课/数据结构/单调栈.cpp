#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, top, a[maxn], st[maxn];
bool empty() {
	return top == 0;
}

void pop() {
	top--;
}

void push(int x) {
	int res = -1;
	while(!empty() && st[top] >= x) pop(); //集训队淘汰人（这次是<，因此要改一改） 
	cout << (empty() ? -1 : st[top]) << " "; //如果人没有了，就输出-1 
	st[++top] = x; //否则把人加进来 
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) push(a[i]); 
	return 0;
}
