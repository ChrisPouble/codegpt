#include <bits/stdc++.h>
using namespace std;

int c[25], cnt[26];

int main() {
    int X; cin >> X;

    for (int i = 0; i < 25; i++) {
        c[i] = min(25, X);
        X -= c[i];
    }

    for (int i = 0; i < 25; i++)
        cnt[c[i]]++;

    string str = "";
    for (int y = 25; y >= 0; y--) {
        for (int i = 0; i < cnt[y]; i++)
            str += "A";
        if (y > 0) str += "C";
    }

    string ans = "";
    for (int i = 0; i < 50; i++) {
        ans += str[i];
        if (i < 49) ans += "R";
    }

    cout << ans << "\n";
    return 0;
}