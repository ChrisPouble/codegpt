#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, son[maxn][26], cnt[maxn], idx;
/*
son[i][j]表示第i个节点有没有j这个字母这个儿子
cnt[i]表示以这个节点为单词结尾的单词数量的个数
idx表示所有节点的下标，0即表示根节点，也表示空节点
*/
void insert(string C) {
	int p = 0;
	for (int i = 0; C[i]; i++) {
		int u = C[i] - 'a';
		if(!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}

int query(string C) {
	int p = 0;
	for (int i = 0; C[i]; i++) {
		int u = C[i] - 'a';
		if(!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}

signed main() {
	cin >> n;
	while(n--) {
		string opt, X;
		cin >> opt >> X;
		if(opt == "I") insert(X);
		else cout << query(X) << "\n";
	}
	return 0;
}
