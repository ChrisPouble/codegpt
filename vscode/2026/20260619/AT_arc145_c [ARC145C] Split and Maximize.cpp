#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    int n; cin >> n;
    long long ans = 1ll;
    
    for (int i = n + 2; i <= 2 * n; i++)
        ans = (ans * i) % mod;
    
    for (int i = 1; i <= n; i++)
        ans = (ans * 2) % mod;
    
    cout << ans << "\n";
    
    return 0;
}