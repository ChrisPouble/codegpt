#include <bits/stdc++.h>
#define maxn 30010
using namespace std;

int n, m, v, w, f[maxn];
signed main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        w *= v;
        for (int j = m; j >= 1; j--)
            if(j >= v) f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}
