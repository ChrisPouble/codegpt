#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int A, B, n, ans = 1e9;
int a[maxn][maxn], row_max[maxn][maxn], col_max[maxn][maxn], row_min[maxn][maxn], col_min[maxn][maxn], q[maxn];
signed main() {
    cin >> A >> B >> n;
    for (int i = 1; i <= A; i++)
        for (int j = 1; j <= B; j++)
            cin >> a[i][j];
    for (int i = 1; i <= A; i++) {
        int hh = 0, tt = 0;
        memset(q, 0, sizeof(q));
        for (int j = 1; j <= B; j++) {
            while(hh <= tt && j - q[hh] >= n) hh++;
            while(hh <= tt && a[i][j] >= a[i][q[tt]]) tt--;
            q[++tt] = j;
            if(j >= n) row_max[i][j - n + 1] = a[i][q[hh]];
        }
    }
    for (int i = 1; i <= B - n + 1; i++) {
        int hh = 0, tt = 0;
        memset(q, 0, sizeof(q));
        for (int j = 1; j <= A; j++) {
            while(hh <= tt && j - q[hh] >= n) hh++;
            while(hh <= tt && row_max[j][i] >= row_max[q[tt]][i]) tt--;
            q[++tt] = j;
            if(j >= n) col_max[j - n + 1][i] = row_max[q[hh]][i];
        }
    }
    for (int i = 1; i <= A; i++) {
        int hh = 0, tt = 0;
        memset(q, 0, sizeof(q));
        for (int j = 1; j <= B; j++) {
            while(hh <= tt && j - q[hh] >= n) hh++;
            while(hh <= tt && a[i][j] <= a[i][q[tt]]) tt--;
            q[++tt] = j;
            if(j >= n) row_min[i][j - n + 1] = a[i][q[hh]];
        }
    }
    for (int i = 1; i <= B - n + 1; i++) {
        int hh = 0, tt = 0;
        memset(q, 0, sizeof(q));
        for (int j = 1; j <= A; j++) {
            while(hh <= tt && j - q[hh] >= n) hh++;
            while(hh <= tt && row_min[j][i] <= row_min[q[tt]][i]) tt--;
            q[++tt] = j;
            if(j >= n) col_min[j - n + 1][i] = row_min[q[hh]][i];
        }
    }
    for (int i = 1; i <= A - n + 1; i++)
        for (int j = 1; j <= B - n + 1; j++)
            ans = min(col_max[i][j] - col_min[i][j], ans);
    cout << ans << endl;
    return 0;
}
