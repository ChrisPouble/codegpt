#include <bits/stdc++.h>
using namespace std;

int read() { //快读 
	int x = 0;
	char c = getchar();
	while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c - 48), c = getchar();
	return x;
}

int n, a[10];
unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, bool> > > > >vis; //unordered_map更快 
int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[1] = read(), a[2] = read(), a[3] = read(), a[4] = read(), a[5] = read(); //读入 
		sort(a + 1, a + 6); //排序 
		if(!vis[a[1]][a[2]][a[3]][a[4]][a[5]]) { //如果以前没买过 
			vis[a[1]][a[2]][a[3]][a[4]][a[5]] = 1; //进行标记 
			putchar('b'); //putchar有点长 
			putchar('u');
			putchar('y');
			putchar('\n');
		} else {
			putchar('p');
			putchar('a');
			putchar('s');
			putchar('s');
			putchar('\n');
		}
	}
	return 0;
}
