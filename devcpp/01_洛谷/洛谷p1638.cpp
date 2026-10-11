#include <bits/stdc++.h>
using namespace std;

int n, m, ansl, ansr, a[1000010], sum[2010]; //sum表示看过某位画家的画的数量 
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1, r = 1, num = 0, ans = 100000000; //num表示看过几位画家的画，ans表示最优的a和b之间的距离 
	while(l <= r && r <= n + 1) { //条件 
		if(num < m) { //如果数量还没达到 
			r++; //没到达就往后面加
			sum[a[r - 1]]++; //数量也加上 
			if(sum[a[r - 1]] == 1) num++; //如果第一次看过a[r - 1]的画，num++ 
		} else { //如果数量达到了
			if(ans > r - l) { //如果发现更小并且可以满足的距离 
				ans = r - l; //更新距离 
				ansl = l; //更新左端点 
				ansr = r - 1; //更新右端点 
			}
			l++; //看看如果去掉第一个数，接着进行判断 
			if(sum[a[l - 1]] == 1) num--; //num也会少一个 
			sum[a[l - 1]]--; //看过a[l - 1]的画的数量少一个 
		}
	}
	cout << ansl << " " << ansr << endl; //输出 
	return 0;
} 
