#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, b;
signed main() {
    cin >> n >> m;

    int p = (n - 1) * (n - 2) / 2;

    if (m > p) {
        cout << "-1" << endl;
        return 0;
    }

    int now = p - m;
    int ans = n - 1 + now;
    
    cout << ans << endl;
    for (int i = 2; i <= n; i++) {
        cout << "1 " << i << endl;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i == j) continue;
            if (!now) return 0;

            cout << i << " " << j << endl;
            now --;
        }
    }

    system("pause");
    return 0;
}