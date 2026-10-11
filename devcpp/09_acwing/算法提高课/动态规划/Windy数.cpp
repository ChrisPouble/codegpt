#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int a, b, f[N][10];
void init() {
    for (int i = 0; i <= 9; i++) f[1][i] = 1;
    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if(abs(j - k) >= 2) f[i][j] += f[i - 1][k];
}

int dp(int n) {
    if (!n) return 0; //不包含前导0
    
    vector<int>num;
    while(n) num.push_back(n % 10), n /= 10;
    
    int res = 0, ls = -10;
    for (int i = num.size() - 1; i >= 0; i--) {
        int x = num[i];
        for (int j = (i == num.size() - 1); j < x; j++)
            if(abs(j - ls) >= 2) res += f[i + 1][j];
        if(abs(ls - x) < 2) break;
        ls = x;
        if(!i) res++;
    }
    
    for (int i = 1; i < num.size(); i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    return res;
}

signed main() {
    init();
    cin >> a >> b;
    cout << dp(b) - dp(a - 1) << endl;
    return 0;
}
