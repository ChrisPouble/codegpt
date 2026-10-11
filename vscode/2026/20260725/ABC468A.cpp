// Problem: ATcoder - Maximal Value
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
    int n; cin >> n; 
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        if (a[i] < a[i + 1] && a[i + 1] > a[i + 2])
            ans++;
    }

    cout << ans << endl;

    return 0;
}