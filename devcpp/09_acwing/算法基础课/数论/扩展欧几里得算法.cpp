#include <bits/stdc++.h>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1, y = 0; //b = 0的情况 
		return a;
	}
	int d = exgcd(b, a % b, y, x); //把x和y颠倒过来，方便后面的计算 
	y -= a / b * x; //x不用动，y要动 
	return d;
}

int n, a, b;
int main() {
	scanf("%d", &n);
	while(n--) {
		int a, b, x = 0, y = 0;
		scanf("%d%d", &a, &b);
		exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	return 0;
}
