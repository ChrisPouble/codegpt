#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, cnt;
string S[155], T;

struct Acnode {
	int son[26], fail, tot, belong;
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
	++Ac[now].tot; 
	Ac[now].belong = id;
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
			if (son(now, i)) {
				fail(son(now, i)) = son(fail(now), i);
				q.push(son(now, i));
			} else {
				son(now, i) = son(fail(now), i);
			}
		}
	}
}

int match_cnt[N];

// 与文本串匹配
void query(const string& str) {
	int len = str.length(), now = 0;

	for (int i = 0; i < len; i++) {
		int ch = str[i] - 'a';
		now = son(now, ch);
		for (int j = now; j; j = fail(j)) {
			if (!Ac[j].belong) continue;
            match_cnt[Ac[j].belong]++;
		}
	}
    
	// 找出最大出现次数
	int max_ans = 0;
	for (int i = 1; i <= n; i++) {
		max_ans = max(max_ans, match_cnt[i]);
	}
    
	cout << max_ans << "\n";
	for (int i = 1; i <= n; i++) {
		if (match_cnt[i] == max_ans) {
			cout << S[i] << "\n";
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	while (cin >> n && n) {
		for (int i = 0; i <= cnt; i++)
			memset(&Ac[i], 0, sizeof(Acnode));
        
        cnt = 0;
        for (int i = 1; i <= n; i++)
            match_cnt[i] = 0;
        
		for (int i = 1; i <= n; i++) 
			cin >> S[i], InsertString(i);
    
		cin >> T, getFailPointer();
		query(T);
	}

	return 0;
}