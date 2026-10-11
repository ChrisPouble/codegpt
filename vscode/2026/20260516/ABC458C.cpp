#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    long long ans = 0;
    s = " " + s;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == 'C') ans += min(i, (int)s.size() - i);

    cout << ans << endl;

    return 0;
}