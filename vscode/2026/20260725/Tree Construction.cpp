// Problem: HDU - Tree Construction
// Contest: 2010 ACM-ICPC Multi-University Training Contest（8）
// URL: https://vjudge.net/problem/HDU-3516
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int x[N], s[N][N], f[N][N], n, y[N], h;

void solve() {
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
        s[i][i] = i;
    }
	
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            h = s[i][j - 1];
            for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++) {
                if (f[i][k] + f[k + 1][j] + (x[k + 1] - x[i]) + (y[k] - y[j]) < f[i][j]) {
                    f[i][j] = f[i][k] + f[k + 1][j] + (x[k + 1] - x[i]) + (y[k] - y[j]);
                    h = k;
                }
                s[i][j] = h;
            }
        }
    }
    
    cout << f[1][n] << endl;
}

int main() {
    while (cin >> n) solve();
    return 0;
}