// Problem: ATcoder - Pre-Palindrome
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;

    int len = s.size();
    s = ' ' + s;

    int ans = 0;
    for (int i = 1; i <= len; i++) {
        int l = i, r = i, cnt = 0;
        
        while (l >= 1 && r <= len && (s[l] == s[r] || cnt == 0)) {
            cnt += (s[l] != s[r]);
            ans++, l--, r++;
        }
    }

    for (int i = 1; i < len; i++) {
        int l = i, r = i + 1, cnt = 0;
        
        while (l >= 1 && r <= len && (s[l] == s[r] || cnt == 0)) {
            cnt += (s[l] != s[r]);
            ans++, l--, r++;
        }
    }

    cout << ans << endl;

    return 0;
}