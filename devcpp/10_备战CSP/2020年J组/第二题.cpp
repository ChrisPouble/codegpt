#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, w, a[maxn], b[maxn]; //b[i]表示成绩为i的选手的个数 
int main() {
	scanf("%d%d", &n, &w); 
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		int x = max(1, i * w / 100); //计算分数线的位置 
		b[a[i]]++; //数量+1
		for (int k = 600, cnt = 0; k >= 0; k--) { //由于要从大到小，因此从后面开始遍历 
			cnt += b[k]; //加上成绩为k的选手的数量 
			if(cnt >= x) { //如果数量已经超过x 
				printf("%d ", k); //则输出 
				break;
			}
		}
	}
	return 0;
}
