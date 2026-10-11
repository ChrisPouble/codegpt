#include <bits/stdc++.h>
using namespace std;

const int N = 35, M = 110;
int a, b, p, f[N][10][M];
int mod(int x, int y) {
    return (x % y + y) % y;
}

void init() {
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= 9; i++) f[1][i][i % p]++;
    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < p; k++)
                for (int x = 0; x <= 9; x++)
                    f[i][j][k] += f[i - 1][x][mod(k - j, p)];
}

int dp(int n) {
    if(!n) return 1;
    
    vector<int>num;
    while(n) num.push_back(n % 10), n /= 10;
    
    int res = 0, ls = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int x = num[i];
        for (int j = 0; j < x; j++)
            res += f[i + 1][j][mod(-ls, p)];
        ls += x;
        if (!i && ls % p == 0) res++; 
    }
    return res;
}

void solve() {
    init();
    cout << dp(b) - dp(a - 1) << endl;
}

signed main() {
    while(cin >> a >> b >> p) solve();
    return 0;
}
