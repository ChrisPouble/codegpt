#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int main() {
    cin >> n >> m >> q;

    for (int i = 1, opt, x; i <= q; i++) {
        cin >> opt >> x;

        if (opt == 1) cout << x * m << endl, n -= x;
        else cout << x * n << endl, m -= x;
    }

    return 0;
}