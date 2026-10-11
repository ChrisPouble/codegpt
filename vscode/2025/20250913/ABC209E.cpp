#include <bits/stdc++.h>
using namespace std;

const int M = 52 * 52 * 52;
const int N = 2e5 + 10;

int n;
int ans[N], cnt[N];
pair<int, int> edge[N];
vector<int> linker[N];
string a[N];

int char_to_int(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

int string_to_int(char a,char b,char c) {
    return char_to_int(a) * 52 * 52 + char_to_int(b) * 52 + char_to_int(c);
}

int main() {
    memset(ans, -1, sizeof(ans));

    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        edge[i] = { string_to_int(s[0], s[1], s[2]), string_to_int(s[s.size() - 3], s[s.size() - 2], s[s.size() - 1]) };
        cnt[edge[i].first]++;

        linker[edge[i].second].push_back(edge[i].first);
    }
    
    queue<int> que;
    for (int i = 0; i < M; i++)
        if (cnt[i] == 0) {
            ans[i] = 0;
            que.push(i);
        }

    while (!que.empty()) {
        int h = que.front();
        que.pop();

        for (int x : linker[h])
            if (ans[x] == -1) {
                cnt[x]--;
                if (ans[h] == 0) ans[x] = 1, que.push(x); // 如果存在后继必败 -> x 必胜
                else if (cnt[x] == 0) ans[x] = 0, que.push(x); // 如果后继全是必胜 -> x 必败
            }
    }

    for (int i = 1; i <= n; i++) {
        if (ans[edge[i].second] == -1) cout << "Draw" << endl; // 平局
        if (ans[edge[i].second] == 0) cout << "Takahashi" << endl; // 赢
        if (ans[edge[i].second] == 1) cout << "Aoki" << endl; // 输
    }

    system("pause");

    return 0;
}