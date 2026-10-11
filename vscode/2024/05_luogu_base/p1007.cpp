#include <bits/stdc++.h>
using namespace std;

int L, n, maxt, mint, a[5010];
int main() {
    cin >> L >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        maxt = max(maxt, max(a[i], L + 1 - a[i]));
        mint = max(mint, min(a[i], L + 1 - a[i]));
    }
    cout << mint << " " << maxt << endl;
    return 0;
}