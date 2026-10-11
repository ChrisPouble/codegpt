#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, son[maxn * 31][2], a[maxn], ans, idx;
/*
son[i][j]表示第i个节点有没有j这个字母这个儿子（因为最多有n个数，每个数转成二进制最多有31位，所以第一位要考到31*maxn） 
idx表示所有节点的下标，0即表示根节点，也表示空节点
*/
void insert(int C) {
	int p = 0;
	for (int i = 30; i >= 0; i--) {
		int u = (C >> i) % 2;
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	//长度都一样就不用cnt数组标记最后一位了
}

int query(int C) {
	int p = 0, res = 0;
	for (int i = 30; i >= 0; i--) {
		int u = (C >> i) % 2;
		if(son[p][!u]) { //如果有异或这一条路 
			p = son[p][!u]; //就异或 
			res = res * 2 + 1; //计算值 
		} else { //否则选择另一条路 
			p = son[p][u];
			res = res * 2 + 0;
		}
	}
	return res;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], insert(a[i]);
	for (int i = 1; i <= n; i++) ans = max(ans, query(a[i]));
	cout << ans << endl;
	return 0;
}
