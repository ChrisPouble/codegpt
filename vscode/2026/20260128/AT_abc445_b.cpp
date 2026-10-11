#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

int n;
string s[N];
signed main() {
    cin >> n;

    int siz = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        siz = max(siz, (int)s[i].size());
    }
    
    for (int i = 1; i <= n; i++) {
        int p = siz - s[i].size();
        for (int k = p / 2; k; k--) cout << ".";
        cout << s[i];
        for (int k = p / 2; k; k--) cout << ".";
        cout << endl;
    }

    system("pause");
    return 0;
}