#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m, a[N], b[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int j = 1; j <= m; ++j)
        cin >> b[j];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int i = 1, j = 1;
    int ans = 0;

    while (i <= n && j <= m) {
        if (b[j] <= 2 * a[i]) ans++, i++, j++;
        else i++;
    }

    cout << ans << "\n";

    system("pause");
    return 0;
}