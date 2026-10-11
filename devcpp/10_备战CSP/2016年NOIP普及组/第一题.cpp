#include <bits/stdc++.h>
#define int long long
using namespace std;

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int n, a1, b1, a2, b2, a3, b3; 
signed main() {
	n = read(), a1 = read(), b1 = read(), a2 = read(), b2 = read(), a3 = read(), b3 = read();
	int t1 = (n + a1 - 1) / a1 * b1; //计算第一种包装 
	int t2 = (n + a2 - 1) / a2 * b2; //计算第二种包装 
	int t3 = (n + a3 - 1) / a3 * b3; //计算第三种包装 
	write(min(min(t1, t2), t3)); //取最小值 
	return 0;
}
