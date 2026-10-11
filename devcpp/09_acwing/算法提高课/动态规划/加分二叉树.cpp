#include <bits/stdc++.h>
#define maxn 35
using namespace std;

int n, w[maxn], f[maxn][maxn], root[maxn][maxn];
void dfs(int l, int r) {
    if(l > r) return;
    int k = root[l][r];
    cout << k << " ";
    dfs(l, k - 1);
    dfs(k + 1, r);
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int l = n; l >= 1; l--)
        for (int r = l; r <= n; r++) {
            for (int k = l; k <= r; k++) {
                int left = l == k ? 1 : f[l][k - 1];
                int right = r == k ? 1 : f[k + 1][r];
                int score = left * right + w[k];
                if(l == r) score = w[k];
                if(f[l][r] < score) {
                    f[l][r] = score;
                    root[l][r] = k;
                }
            }
        }
    cout << f[1][n] << endl;
    dfs(1, n);
    return 0;
}
