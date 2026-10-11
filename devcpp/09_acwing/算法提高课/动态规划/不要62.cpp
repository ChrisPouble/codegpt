#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 35;
int a, b, f[N][10];
void init() {
    for (int i = 0; i <= 9; i++) if(i != 4) f[1][i] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++) {
            if (j == 4) continue;
            for (int k = 0; k <= 9; k++) {
                if(k == 4 || (j == 6 && k == 2)) continue;
                f[i][j] += f[i - 1][k];
            }
        }
}

int dp(int n) {
    if(!n) return 1;
    
    vector<int>num;
    while (n) num.push_back(n % 10), n /= 10;
    
    int res = 0, ls = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int x = num[i];
        for (int j = 0; j < x; j++) {
            if ((ls == 6 && j == 2) || (j == 4)) continue;
            res += f[i + 1][j];
        }
        if((ls == 6 && x == 2) || (x == 4)) break;
        ls = x;
        if(!i) res++;
    }
    return res;
}

void solve() {
    cout << dp(b) - dp(a - 1) << endl;
}

signed main() {
    init();
    while(cin >> a >> b && a && b) solve();
    return 0;
}
