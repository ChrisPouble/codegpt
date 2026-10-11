#include <bits/stdc++.h>
#define int long long
#define maxn 200010
using namespace std;

int n, res, b[maxn];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i], res ^= b[i];
    for (int i = 1; i <= n; i++) cout << (res ^ b[i]) << " ";
    return 0;
}