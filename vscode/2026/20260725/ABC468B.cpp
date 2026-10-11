// Problem: ATcoder - Corridor Watch
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[110];

int main() {
    int n, g; cin >> n >> g >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') continue;
        for (int j = max(0, i - g), siz = min(i + g, (int)s.size() - 1); j <= siz; j++)
            vis[j] = 1;
    }
    
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += (!vis[i]);
    }

    cout << ans << endl;

    return 0;
}