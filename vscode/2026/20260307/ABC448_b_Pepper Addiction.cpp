#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, c[N];
int main() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> c[i];

    int ans = 0;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;

        if (c[a] >= b) ans += b, c[a] -= b;
        else ans += c[a], c[a]  =0;
    }

    cout << ans << endl;

    return 0;
}
