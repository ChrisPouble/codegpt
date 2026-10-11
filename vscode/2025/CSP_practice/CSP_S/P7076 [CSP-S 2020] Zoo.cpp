#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

const int N = 70;

ull n, m, c, k;

int buc[N], lim[N];
ull ans, hv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	cin >> n >> m >> c >> k;

    // if (n == 1 && m == 0 && c == 1 && k == 64) {
    //     cout << -1 << endl;
    //     return 0;
    // }
    
	for (int i = 1; i <= n; i++) {
        ull x;
        cin >> x;

        for (ull j = 0; j < 64; j++)
            buc[j] |= (x >> j) & 1;
    }

    for (int i = 1; i <= m; i++) {
        ull p, q;
        cin >> p >> q;

        p = (1ull << p);
        for (ull j = 0; j < 64; j++)
            lim[j] |= (p >> j) & 1;
    }

    for (int i = 0; i < k; i++)
        ans += (!lim[i]) || buc[i];
    
    if (ans == 64 && n == 0) cout << "18446744073709551616" << endl;
    else if (ans == 64 && n == 1) cout << "18446744073709551615" << endl;
    else cout << (1ull << ans) - n << endl;

    system("pause");
	return 0;
}