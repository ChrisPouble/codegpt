#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int n, m;
stack<char> ans;
char g[3][5];
unordered_map<string, pair<char, string> >pre;
unordered_map<string, int> dis;
void st(string state) {
    for (int i = 0; i < 4; i++) g[1][i] = state[i]; // 将状态的前四个字符赋值给g的第一行
    for (int i = 7, j = 0; j < 4; i--, j++) g[2][j] = state[i]; // 将状态的后四个字符赋值给g的第二行
}

string get() {
	string res;
    for (int i = 0; i < 4; i++) res += g[1][i]; // 将g的第一行字符拼接成字符串
    for (int i = 3; i >= 0; i--) res += g[2][i]; // 将g的第二行字符逆序拼接成字符串
    return res;
}

string move0(string state) {
    st(state);
    for (int i = 0; i < 4; i++) swap(g[1][i], g[2][i]); // 交换g的第一行和第二行的字符
    return get();
}

string move1(string state) {
    st(state);
    int v0 = g[1][3], v1 = g[2][3]; // 保存g的第一行和第二行的最后一个字符
    for (int i = 3; i > 0; i--) {
        g[1][i] = g[1][i - 1]; // 将g的第一行字符向右移动一位
        g[2][i] = g[2][i - 1]; // 将g的第二行字符向右移动一位
    }
    g[1][0] = v0, g[2][0] = v1; // 将保存的字符放到g的第一行和第二行的第一个位置
    return get();
}

string move2(string state) {
    st(state);
    int v = g[1][1]; // 保存g的第一行的第二个字符
    g[1][1] = g[2][1]; // 将g的第二行的第二个字符赋值给g的第一行的第二个字符
    g[2][1] = g[2][2]; // 将g的第二行的第三个字符赋值给g的第二行的第二个字符
    g[2][2] = g[1][2]; // 将g的第一行的第三个字符赋值给g的第二行的第三个字符
    g[1][2] = v; // 将保存的字符放到g的第一行的第三个位置
    return get();
}

int bfs(string st, string en) {
	if (st == en) return 0;
    queue<string>q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty()) {
        string t = q.front();
		q.pop();
		string m[3];
		m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);
		for (int i = 0; i < 3; i++) {
            if (!dis.count(m[i])) {
            	dis[m[i]] = dis[t] + 1;
            	pre[m[i]] = {'A' + i, t};
            	q.push(m[i]);
            	if (m[i] == en) return dis[m[i]];
			}
        }
    }
    return -1;
}

signed main() {
	string st, en;
	for (int i = 0, x; i < 8; i++) {
		cin >> x;
		en += char(x + '0');
	}
	for (int i = 1; i <= 8; i++) st += char('0' + i);
	cout << bfs(st, en) << endl;
	while (en != st) {
		ans.push(pre[en].first);
		en = pre[en].second;
	}
	while (!st.empty()) {
		cout << ans.top();
		ans.pop();
	}
    return 0;
}
