#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;
const int M = 20;

int n, m, a[N];
int f[N][M], lg2[N];

void init() {
    lg2[1] = 0;
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;

    for (int j = 1; j < M; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int get(int l, int r) {
    int len = lg2[(r - l + 1)];
    return min(f[l][len], f[r - (1 << len) + 1][len]);
}

int k, b[10];
int lst[10], rst[10];

void solve() {
    cin >> k;

    for (int i = 1; i <= k; i++)
        cin >> b[i];

    b[0] = 0, b[k + 1] = n;

    int cnt = 0;
    for (int i = 0; i <= k; i++) {
        if (b[i] + 1 > b[i + 1] - 1) continue;
        lst[++cnt] = b[i] + 1, rst[cnt] = b[i + 1] - 1;
        // cout << lst[cnt] << " " << rst[cnt] << endl;
    }

    int ans = 1e9;
    for (int i = 1; i <= cnt; i++) ans = min(ans, get(lst[i], rst[i]));
    for (int i = 0; i <= k; i++) lst[i] = rst[i] = b[i] = 0;

    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][0] = a[i];
    }

    init();

    while (m--) solve();

    return 0;
}
