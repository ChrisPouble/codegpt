#include <bits/stdc++.h>
#define maxn 40010
#define N 100010 //开的大一点没有害处 
using namespace std;

int read() { //快读
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) { //快写
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int n, m, cnt[N], ans[maxn][5], x[maxn];
int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) x[i] = read(), cnt[x[i]]++; //记录数量
	for (int t = 1; t * 9 <= n - 2; t++) {
		for (int d = 9 * t + 2, sum = 0; d <= n; d++) {
			int a = d - 9 * t - 1, b = a + 2 * t, c = d - t; //计算a、b、c
			sum += cnt[a] * cnt[b]; //注意这里有可能不同的t组成相同的d，所以要+= 
			ans[c][3] += sum * cnt[d];
			ans[d][4] += sum * cnt[c];
		}
		for (int a = n - 9 * t - 1, sum = 0; a >= 1; a--) { //注意这里要逆推 
			int b = a + 2 * t, c = b + 6 * t + 1, d = c + t; //计算b、c、d 
			sum += cnt[c] * cnt[d];
			ans[a][1] += sum * cnt[b];
			ans[b][2] += sum * cnt[a];
		}
	}
	for (int i = 1; i <= m; ++i) {
		write(ans[x[i]][1]), putchar(' '); //这里不是ans[i][1]，因为我们在上面计算的时候计算的不是下标而是魔法值
		write(ans[x[i]][2]), putchar(' ');
		write(ans[x[i]][3]), putchar(' ');
		write(ans[x[i]][4]), putchar('\n');
	}
	return 0;
}
