#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int M = 1e6 + 10;

struct node {
    int x, y;
} opt[M], tmp[M];

int n, m, a[N];
int dp[M][3];
// dp[i][0] 表示对于第 i 个操作，如果不操作，前 i 个操作的最大新增贡献
// dp[i][1] 表示对于第 i 个操作，如果操作前一个数，前 i 个操作的最大新增贡献
// dp[i][2] 表示对于第 i 个操作，如果不操后一个数，前 i 个操作的最大新增贡献

bool cmp(node p, node q) {
    if (p.x == q.x) return p.y > q.y;
    return p.x < q.x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    
    for (int i = 1; i <= m; i++)
        cin >> opt[i].x >> opt[i].y;

    sort(opt + 1, opt + m + 1, cmp);

    int tot = 0;
    for (int i = 1; i <= m; i++) {
        if (i <= 2) tmp[++tot] = opt[i];
        else if (opt[i].x != opt[i - 2].x) tmp[++tot] = opt[i];
    }

    for (int i = 1; i <= tot; i++)
        opt[i] = tmp[i];

    for (int i = 1; i <= tot; i++) {
        int optx = opt[i].x, opty = opt[i].y;
        int prex = opt[i - 1].x, prey = opt[i - 1].y;

        dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
        dp[i][1] = dp[i][2] = dp[i - 1][0];

        if (i > 1 && prex == optx) dp[i][1] = max({ dp[i][1], dp[i - 1][1] - prey + a[prex] + opty - a[optx], dp[i - 1][2] });
        else if (i > 1 && prex + 1 == optx) dp[i][1] = max({ dp[i][1], dp[i - 1][1], dp[i - 1][2] - prey + a[prex + 1] + opty - a[optx] });
        else dp[i][1] = max({ dp[i][1], dp[i - 1][1] + opty - a[optx], dp[i - 1][2] });

        if (i > 1 && prex + 1 == optx + 1) dp[i][2] = max({ dp[i][2], dp[i - 1][1], dp[i - 1][2] - prey + a[prex + 1] + opty - a[optx] });
        else dp[i][2] = max({ dp[i][2], dp[i - 1][1], dp[i - 1][2] });
    }

    cout << ans + max({ dp[tot][0], dp[tot][1], dp[tot][2] }) << endl;

    return 0;
}