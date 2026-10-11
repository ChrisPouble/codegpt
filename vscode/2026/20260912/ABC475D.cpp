#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;

bool comp[N];
int cnt, prime[N];
int fac[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };

int main() {
    for (int i = 2; i < N; i++) {
        if (comp[i]) continue;
        prime[++cnt] = i;
        for (int j = i + i; j < N; j += i)
            comp[j] = true;
    }

    string S; cin >> S;
    int n = S.size();

    for (int k = 1; k <= cnt; k++) {
        int P = prime[k];

        if (P < fac[n - 1] || P >= fac[n]) continue;

        int mpChar[26], mpDig[10];
        memset(mpChar, -1, sizeof(mpChar));
        memset(mpDig, -1, sizeof(mpDig));

        bool ok = true;

        for (int i = 1; i <= n; i++) {
            int d = (P / fac[n - i]) % 10;
            int c = S[i - 1] - 'a';

            if (mpChar[c] != -1 && mpChar[c] != d) {
                ok = false; break;
            }

            if (mpDig[d] != -1 && mpDig[d] != c) {
                ok = false; break;
            }

            mpChar[c] = d; mpDig[d] = c;
        }

        if (ok) { cout << P << "\n"; return 0; }
    }

    cout << -1 << "\n";
    return 0;
}