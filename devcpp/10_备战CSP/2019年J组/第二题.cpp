#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, ans, h = 1, t = 1; //手写队列的头和尾 
struct node {
	int t, val;
}q[maxn]; //手写队列 

int main() {
	cin >> n;
	while(n--) {
		int d, time, val;
		cin >> d >> val >> time;
		if(d == 0) {
			ans += val;
			q[t++] = {time, val}; //放入队尾 
		} else {
			bool is = 0; //判断是否可以不花钱
			while(h < t && time - q[h].t > 45) h++; //筛掉不必要的地铁票 
			for (int i = h; i < t; i++) //枚举剩下的地铁票 
				if(q[i].val >= val) { //如果合格了
					for (int j = i + 1; j < t; j++)
						q[j - 1] = q[j]; //则删除 
					t--; //地铁票数量-1 
					is = 1;
					break;
				}
			if(!is) ans += val; //老老实实买公交车票 
		}
	}
	cout << ans << endl;
	return 0;
}
