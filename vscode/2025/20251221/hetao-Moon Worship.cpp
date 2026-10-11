/*
1. 首先先写原始 DP
  - f[i][j] 表示以第 i 天为开始的 j 天中，有多少中合法的方案
  - 延长序列(j 变 j + 1)：f[i + 1][j + 1] += f[i][j] * (m - j)
  - 截断序列(j 变 k)：f[i + 1][k] += f[i][j]（1 <= k <= j）
  - 答案：sum(f[n][i])
2. 矩阵优化 DP（状态从 p 变为 q）
  - 延长序列：如果 q = p + 1，即 p = q - 1，因此系数为 m - (p + 1) = m - r
  - 截断序列：如果 r <= c，即 c >= r，则系数为 1

注意这里的 T 是转移矩阵，并非我们的初始矩阵，初始矩阵为 {m, 0, 0, 0...0} ^ T
*/

#include <bits/stdc++.h>
#define ll long long
#define Matrix vector<vector<ll> >
using namespace std;

const int mod = 1e9 + 7;

ll n, m;

// 矩阵乘法
Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
        }
    }
    return C;
}

// 矩阵快速幂
Matrix power(Matrix A, ll p) {
    int n = A.size();
    Matrix Res(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) Res[i][i] = 1; // 单位矩阵
    while (p > 0) {
        if (p & 1) Res = multiply(Res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return Res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if (n == 1ll) {
        cout << m % mod << endl;
        return 0;
    }

    int size = m - 1;
    Matrix T(size, vector<ll>(size, 0));

    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            if (c == r - 1)  T[r][c] = (T[r][c] + (m - (c+1))) % mod;
            if (c >= r) T[r][c] = (T[r][c] + 1) % mod;
        }
    }

    Matrix Tn = power(T, n - 1);

    ll ans = 0;
    for (int i = 0; i < size; i++)
        ans = (ans + Tn[i][0]) % mod;
        
    // 最后乘上初始的 m 种情况
    ans = (ans * m) % mod;

    cout << ans << endl;

    return 0;
}