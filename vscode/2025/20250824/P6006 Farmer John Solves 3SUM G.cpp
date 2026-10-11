#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e3 + 10;
const int K = 1e6;

int n, m, a[N];
int s[N][N];
int cnt[3 * K];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += K;

    for (int i = 1; i <= n; i++) {
        cnt[a[i + 1]]++;
        for (int j = i + 2; j <= n; j++) {
            if (a[i] + a[j] <= K * 3 && a[i] + a[j] >= K) s[i][j] = cnt[3 * K - a[i] - a[j]];
            cnt[a[j]]++;
        }
        for (int j = i + 1; j <= n; j++)
            cnt[a[j]]--;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    // for (int i = 1; i <= n; i++, puts(""))
    //     for (int j = 1; j <= n; j++)
    //         cout << s[i][j] << " ";

    while (m--) {
        int l, r;
        cin >> l >> r;

        cout << s[r][r] - s[l - 1][r] - s[r][l - 1] + s[l - 1][l - 1] << "\n";
    }

    // system("pause");
    return 0;
}