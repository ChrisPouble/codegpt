#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin >> s, s = " " + s;

    int ans = 0, len = s.size() - 1;
    for (int i = 1; i <= len; i++) {
        int l1 = i, r1 = i;
        while (s[r1 + 1] == s[l1]) r1++;

        if (r1 == len) break;

        int l2 = r1 + 1, r2 = r1 + 1;
        while (s[r2 + 1] == s[l2]) r2++;
 
        if (s[l1] + 1 == s[l2]) ans += min(r1 - l1, r2 - l2) + 1;
        i = r1;

//        cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    }

    cout << ans << endl;

    return 0;
}
