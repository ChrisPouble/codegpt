#include <bits/stdc++.h>
using namespace std;

int len, A, B, n, m;

void solve() {
	cin >> len >> A >> B;
    n = m = len;
	
    if ((len & 1) || ((A + B) & 1) == 0) {
        cout << "No\n";
        return ;
    }

    cout << "Yes\n";

    int lh = 0, rh = 0;
    int lw = 0, rw = 0;

    while (A > 2) {
        A -= 2;
        n -= 2;
        lh++;
    }

    while (n - A + 1 > 2) {
        n -= 2;
        rh++;
    }

    while (B > 2) {
        B -= 2;
        m -= 2;
        lw++;
    }

    while (m - B + 1 > 2) {
        m -= 2;
        rw++;
    }

    for (int i = 1; i <= lh; i++) {
        for (int j = 2; j <= len; j++)
            cout << "R";
        cout << "D";

        for (int j = 1; j < len; j++)
            cout << "L";
        cout << "D";
    }

    for (int i = 1; i <= lw; i++)
        cout << "DRUR";

    if (A == 1 && B == 2) cout << "DR";
    else cout << "RD";

    for (int i = 1; i <= rw; i++)
        cout << "RURD";

    for (int i = 1; i <= rh; i++) {
        cout << "D";
        for (int j = 1; j < len; j++)
            cout << "L";
        
        cout << "D";
        for (int j = 2; j <= len; j++)
            cout << "R";
    }

    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    int T; cin >> T;
	while (T--) solve();

    // system("pause");
	return 0;
}
