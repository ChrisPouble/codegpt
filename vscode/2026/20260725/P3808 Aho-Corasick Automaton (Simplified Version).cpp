#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6 + 10;

int n, cnt;
string S, T;

struct Acnode {
	int son[26], fail, tot;
	#define son(rt, x) Ac[rt].son[x]
	#define fail(rt) Ac[rt].fail
} Ac[N];

// Trie 树加入模式串
void InsertString(string str) {
	int len = str.length(), now = 0;
	for (int i = 0; i < len; i++) {
		int ch = str[i] - 'a';
		if (!son(now, ch)) 
			son(now, ch) = ++cnt;
		now = son(now, ch);
	}
	++Ac[now].tot;
}

void getFailPointer() {
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (!son(0, i)) continue;
		fail(son(0, i)) = 0, q.push(son(0, i));
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			if (son(now, i)) fail(son(now, i)) = son(fail(now), i), q.push(son(now, i));
			else son(now, i) = son(fail(now), i);
		}
	}
}

int query(string str) {
	int len = str.length(), now = 0, res = 0;
	for (int i = 0; i < len; i++) {
		int ch = str[i] - 'a';

		now = son(now, ch);
		for (int j = now; j && ~Ac[j].tot; j = fail(now))
			res += Ac[j].tot, Ac[j].tot = -1;
	}
	return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n, cnt = fail(0) = 9;
	for (int i = 1; i <= n; i++)
		cin >> S, InsertString(S);
    
	cin >> T, getFailPointer();
	cout << query(T) << "\n";

	return 0;
}