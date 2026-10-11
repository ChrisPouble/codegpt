#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int inf = 0x3f3f3f3f;

int cnt;
int dp[N][N];
string S[N];

struct Acnode {
	int son[26], fail, tot;
	#define son(rt, x) Ac[rt].son[x]
	#define fail(rt) Ac[rt].fail
} Ac[N];

// Trie 树加入模式串
void InsertString(int id) {
	int len = S[id].length(), now = 0;
	for (int i = 0; i < len; i++) {
		int ch = S[id][i] - 'A';
		if (!son(now, ch)) 
			son(now, ch) = ++cnt;
		now = son(now, ch);
	}
    ++Ac[now].tot;
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
                Ac[son(now, i)].tot += Ac[fail(son(now, i))].tot;
				q.push(son(now, i));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int n, k; 
    if (!(cin >> n >> k)) return 0;

    for (int i = 1; i <= n; i++) {
        cin >> S[i];
        InsertString(i);
    }
    
    getFailPointer(); 

    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= cnt; j++) {
            if (dp[i][j] < 0) continue;
            for (int p = 0; p < 3; p++) {
                int v = son(j, p);
                dp[i + 1][v] = max(dp[i + 1][v], dp[i][j] + Ac[v].tot);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= cnt; j++)
        ans = max(ans, dp[k][j]);
    
    cout << ans << "\n";

	return 0;
}