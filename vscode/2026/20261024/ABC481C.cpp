#include <bits/stdc++.h>
using namespace std;

int tot;
map <string, int> mp;

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        string str; cin >> str;
        if (!mp[str]) mp[str] = ++tot;
        cout << mp[str] << "\n";
    }

    return 0;
}