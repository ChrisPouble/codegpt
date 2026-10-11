#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 10;
const int mod = 998244353;

string s, t;
map <char, int> lst, nxt[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s >> t;

    int Siz = s.size(), Tiz = t.size();
    s = ' ' + s, t = ' ' + t;

    for (char c = 'a'; c <= 'z'; c++)
        lst[c] = nxt[Siz + 1][c] = Siz + 1;

    for (int i = Siz; i >= 1; i--) {
        lst[s[i]] = i;
        for (char c = 'a'; c <= 'z'; c++) {
            nxt[i][c] = lst[c];
        }
    }

    int ans = 0;
    for (int i = 1; i <= Siz; i++) {
        int x = i;
        for (int j = 1; j <= Tiz; j++)
            x = nxt[x][t[j]];
        
        if (x == Siz + 1) continue;
        else ans += Siz - x + 1;
    }

    cout << Siz * (Siz - 1) / 2 + Siz - ans << endl;

    system("pause");
    return 0;
}