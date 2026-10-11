#include <bits/stdc++.h>
using namespace std;

const int N = 15;
const int M = 2e5 + 10;

int n, m;
int len[N], idx[N];
string S[M];

map<int, map<int, map<char, bool> > > vis;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> len[i] >> idx[i];

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> S[i];

        int siz = S[i].size();
        for (int j = 0; j < S[i].size(); j++) {
            vis[siz][j + 1][S[i][j]] = 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        string s = S[i];

        bool is = 0;
        if (s.size() != n) is = 1;

        for (int j = 1; j <= n; j++) {
            if (!vis[len[j]][idx[j]][s[j - 1]]) is = 1;
        }

        if (!is) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T = 1;
    // cin >> T;

    while (T--) solve();

    // system("pause");
    return 0;
}