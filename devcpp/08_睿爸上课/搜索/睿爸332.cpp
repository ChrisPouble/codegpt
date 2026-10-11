#include <bits/stdc++.h>
#define int long long
using namespace std;

int read() { //快读 
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) { //快写 
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

int mymin(int x, int y) {return x < y ? x : y;} //手写min函数 
int dx[4] = {-1, 0, 1, 0}; //方位数组 
int dy[4] = {0, -1, 0, 1};
int n, k, a, b, c;
int h = 1, t = 2; //队头指针和队尾指针 
int mp[110][110]; //地图 
int d[110][110]; //目前最小花费。
int kk[110][110]; //当前最小花费时剩余有多少油。
struct node {
	int x, y, o, s; //s表示花费，o（oil）表示剩多少油。
}q[1000010]; //队列 

signed main() {
	n = read(), k = read(), a = read(), b = read(), c = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mp[i][j] = read();
	memset(d, 0x7f, sizeof(d)); //先赋值一个超大的值 
	d[1][1] = 0; //刚开始不用付钱 
	kk[1][1] = k; //拥有的油为k 
	q[h].x = q[h].y = 1, q[h].o = k, q[h].s = 0; //把元素塞进队列里 
	while(h != t) {
		int x = q[h].x;
		int y = q[h].y;
		int o = q[h].o;
		int s = q[h].s;
		if((++h) == 1000000) h = 1; //循环队列 
		for(int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			int to = o;
			int ts = s;
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= n) { //不能超过边界 
				if(tx == n && ty == n) { //如果始终点，那么不用加油 
					d[n][n] = mymin(d[n][n], s); //找最小值 
					continue;
				}
				to--; //拥有的油-1 
				if(mp[tx][ty] == 1) ts += a, to = k; //当前是加油站 
				else if(to == 0) ts += a + c, to = k; //如果不是加油站，并且还没油了，则当地做一个加油站 
				if(i <= 1) ts += b; //如果x坐标或y坐标变小 
				if(ts > d[n][n]) continue; //剪枝 
				if(ts < d[tx][ty]) { //发现可以更新 
					d[tx][ty] = ts;
					kk[tx][ty] = to;
					q[t].x = tx, q[t].y = ty, q[t].o = to, q[t].s = ts, t++;
				} else if(to > kk[tx][ty] && ts < d[tx][ty] + a + c) q[t].x = tx, q[t].y = ty, q[t].o = to, q[t].s = ts, t++;
				//留条活路给比目前最小费用高但剩的油多的。
				//因为目前的最小花费未来可能会因油不够而加油，加油后费用比这个费用要高。 
			}
			if(t == 1000000) t = 1; 
		}
	}
	write(d[n][n]);
	return 0;
}
