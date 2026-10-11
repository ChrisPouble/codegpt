#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, cnt;
int indeg[N], ans[N], mp[N];
string S[N], T;

struct Acnode {
	int son[26], fail, end, flag;
	#define son(rt, x) Ac[rt].son[x]
	#define fail(rt) Ac[rt].fail
} Ac[N];

// Trie 树加入模式串
void InsertString(int id) {
	int len = S[id].length(), now = 0;
	for (int i = 0; i < len; i++) {
		int ch = S[id][i] - 'a';
		if (!son(now, ch)) 
			son(now, ch) = ++cnt;
		now = son(now, ch);
	}
    
    if (!Ac[now].end) Ac[now].end  = id;
    mp[id] = Ac[now].end;
}

// 寻找 Fail 指针
void getFailPointer() {
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (son(0, i)) {
			fail(son(0, i)) = 0;
			q.push(son(0, i));
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < 26; i++) {
			if (!son(now, i)) {
				son(now, i) = son(fail(now), i);
			} else {
				fail(son(now, i)) = son(fail(now), i);
				indeg[fail(son(now, i))]++, q.push(son(now, i));
			}
		}
	}
}

void ToFlag(string str) {
    int len = str.length(), now = 0;
	for (int i = 0; i < len; i++) {
		int ch = str[i] - 'a';
		now = son(now, ch), Ac[now].flag++;
	}
}

// 与文本串匹配
void Query(const string& str) {
	queue <int> q;
	for (int i = 1; i <= cnt; i++)
        if (!indeg[i]) q.push(i);
    
	while (!q.empty()) {
		int now = q.front(); q.pop();

		ans[Ac[now].end] = Ac[now].flag;

		int nxt = fail(now);
		Ac[nxt].flag += Ac[now].flag;
		if (!--indeg[nxt]) q.push(nxt);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> n, cnt = 0;
	for (int i = 1; i <= n; i++) 
		cin >> S[i], InsertString(i);
    
	getFailPointer();
	cin >> T, ToFlag(T), Query(T);

	for (int i = 1; i <= n; i++)
		cout << ans[mp[i]] << "\n";

	return 0;
}