#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, tot;
int cnt[N * 70], son[N * 70][15];
vector<int> ans[N * 70];
string s;

void insert(string s, int d, int id) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int v = s[i] - 'a';
        if (!son[pos][v]) son[pos][v] = ++tot;
        pos = son[pos][v];

        cnt[pos] += d;
        if (cnt[pos] > ans[pos].size())
            ans[pos].push_back(id);
    }
}

int query(string s, int k) {
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int v = s[i] - 'a';
        if (!son[pos][v]) return -1;

        pos = son[pos][v];

        if (ans[pos].size() <= k) return -1;
    }
    return ans[pos][k];
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n;

    string s;
    int a, b, c, opt;
    int last_ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> opt;

        if (opt == 1 || opt == 2) {
            cin >> s;
            insert(s, opt == 1 ? 1 : -1, i);
        } else {
            cin >> s;
            cin >> a >> b >> c;
            
            long long d = (1ll * a * last_ans + b) % c;
            last_ans = query(s, d);

            cout << last_ans << "\n";

            last_ans = abs(last_ans);
        }
    }

    system("pause");
    return 0;
}