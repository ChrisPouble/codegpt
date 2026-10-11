// Problem: ATcoder - Between P and Q
// Contest: https://atcoder.jp/contests/abc468
// URL: https://atcoder.jp/contests/abc468/tasks/abc468_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n, a[N], b[N];

int check() {
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }

    return 0;
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    int ans = 0;

    do {
        if (check() == -1) ans++;
        else break;
    } while (next_permutation(a + 1, a + n + 1));

    cout << max(ans - 1, 0) << endl;

    return 0;
}