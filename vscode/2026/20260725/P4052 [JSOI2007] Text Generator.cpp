#include <bits/stdc++.h>
using namespace std;

// 模式串最多 60 个，最大长度 100，所以 AC 自动机节点数最多约 6000
const int N = 110;
const int M = 60 * N; 
const int mod = 10007;

int n, m, cnt;
int dp[N][M];
string S[N];

struct Acnode {
	int son[26], fail, tot;
	#define son(rt, x) Ac[rt].son[x]
	#define fail(rt) Ac[rt].fail
} Ac[M];

// Trie 树加入模式串
void InsertString(int id) {
	int len = S[id].length(), now = 0;
	for (int i = 0; i < len; i++) {
		int ch = S[id][i] - 'A';
		if (!son(now, ch)) 
			son(now, ch) = ++cnt;
		now = son(now, ch);
	}
    Ac[now].tot = 1; 
}

// 寻找 Fail 指针并补全 Trie 图
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
                Ac[son(now, i)].tot |= Ac[fail(son(now, i))].tot;
				q.push(son(now, i));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        InsertString(i);
    }
    
    getFailPointer(); 

    // dp[i][j] 表示生成了长度为 i 的文本，且当前匹配在 AC 自动机的节点 j，且【不包含】任何单词的方案数
    dp[0][0] = 1; 
    
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= cnt; j++) {
            if (!dp[i - 1][j]) continue;
            for (int p = 0; p < 26; p++) {
                int v = son(j, p);
                // 只有当转移过去的节点不包含任何已知单词时（tot == 0），才是“不可读”文本，才允许转移
                if (!Ac[v].tot) dp[i][v] = (dp[i][v] + dp[i - 1][j]) % mod;
            }
        }
    }

    // 统计所有“不可读”文本的总数量
    int unread = 0;
    for (int j = 0; j <= cnt; j++) {
        unread = (unread + dp[m][j]) % mod;
    }
    
    // 统计无条件下的文本总方案数： 26^m
    int all = 1;
    for (int i = 1; i <= m; i++) {
        all = (all * 26) % mod;
    }

    cout << (all - unread + mod) % mod << "\n";

	return 0;
}