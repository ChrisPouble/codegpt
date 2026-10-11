#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int a, b, f[N][10];
void init() {
    for (int i = 0; i <= 9; i++) f[1][i] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = j; k <= 9; k++)
                f[i][j] += f[i - 1][k];
}

int dp(int n) {
    if (!n) return 1;
    
    vector<int>num;
    while(n) num.push_back(n % 10), n /= 10;
    
    int res = 0, lm = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int x = num[i];
        for (int j = lm; j < x; j++)
            res += f[i + 1][j];
        if(lm > x) break;
        lm = x;
        if(!i) res++;
    }
    return res;
}

void solve() {
    cout << dp(b) - dp(a - 1) << endl;
}

signed main() {
    init();
    while(cin >> a >> b) solve();
    return 0;
}
