#include <bits/stdc++.h>
using namespace std;

struct lis{
	int pre, nex, key; //记录前一个数的坐标，后一个数的坐标，自己的编号 
	void csh(int new_pre, int new_nex, int new_key) { //构造函数 
		pre = new_pre;
		nex = new_nex;
		key = new_key;
	}
};

lis s[100010]; //记录每个同学 
int n, m, tot, Hsah[100010]; //tot用来增加同学，Hash记录每位同学所在s数组的坐标 
void left(int x, int y) { //将x插入到y左边 
	int k = Hsah[y]; //取出y的坐标 
	s[++tot].csh(s[k].pre, k, x);
	s[s[k].pre].nex = tot;
	s[k].pre = tot;
	Hsah[x] = tot; //更新x的坐标 
}

void right(int x, int y) { //将x插入到y右边 
	int k = Hsah[y];
	s[++tot].csh(k, s[k].nex, x);
	s[s[k].nex].pre = tot;
	s[k].nex = tot;
	Hsah[x] = tot;
}

void del(int x) {
	int k = Hsah[x];
	if(k == 0) return; //已经被删除了就return 
	s[s[k].pre].nex = s[k].nex;
	s[s[k].nex].pre = s[k].pre;
	Hsah[x] = 0; //归零 
}

int main() {
	s[0].csh(0, 0, 0);
	right(1, 0);
	cin >> n;
	for (int i = 2; i <= n; i++) {
		int k, p; cin >> k >> p;
		if(p == 0) left(i, k);
		else right(i, k);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int t; cin >> t;
		del(t);
	}
	for (int i = s[0].nex; i != 0; i = s[i].nex) //注意这里i要从s[0].nex开始，而不是1，因为队列的开头随时都可能变 
		if(Hsah[i] != 0) cout << s[i].key << " "; //判断是否存在 
		else break;
	return 0;
}
