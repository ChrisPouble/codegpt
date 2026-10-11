#include <bits/stdc++.h>
#define int long long //好习惯 
#define maxn 100010 
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

int n, siz, cnt[maxn];
struct node {
	int time, val; //分别表示达到港口的时间和来自的国家 
};

queue<node>q;
signed main() {
	n = read();
	while(n--) {
		int time = read(), k = read();
		while(k--) { //一个一个的加入 
			int t = read();
			q.push({time, t}); //把这种人加入队列 
			if(cnt[t] == 0) siz++; //如果没有这种国家的人，则siz++ 
			cnt[t]++; //这种国家的人口数量++ 
		}
		while(!q.empty() && q.front().time + 86400 <= time) { //如果队列里的元素没空，且到达港口时间超限(TLE) 
			if(cnt[q.front().val] == 1) siz--; //如果这种国家的人口的数量只剩下一个了，则siz-- 
			cnt[q.front().val]--; //这种国家的人口数量-- 
			q.pop(); //去掉这种人 
		}
		write(siz);
		putchar('\n');
	}
	return 0;
}
