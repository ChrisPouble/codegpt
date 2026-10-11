#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int M = 26;
const int S = 18;
const int inf = 1061109567;

int T, n;
int f[N][N], f1[M][M], f2[N][N];
// f[i][j] 表示凑出 [i, j] 需要多少个 S
// f1[i][j] 表示字母 i 和 j 能凑出谁（状压）
// f2[i][j] 表示 [i, j] 可以合并成哪些字符
string s, w;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);

    cin >> n;
    while (n--) {
        cin >> w;
        f1[w[1] - 'A'][w[2] - 'A'] |= (1 << (w[0] - 'A'));
    }

    cin >> T;
    while (T--) {
        memset(f, 0x3f, sizeof(f));
        memset(f2, 0, sizeof(f2));
        cin >> s;
        int n = s.size();

        s = " " + s;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'S') f[i][i] = 1;
            f2[i][i] |= (1 << (s[i] - 'A'));
        }

        for (int l = n; l >= 1; l--) {
            for (int r = l; r <= n; r++) {
                for (int k = l; k < r; k++) {
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);

                    for (int x = 0; x < M; ++x) {
                        for (int y = 0; y < M; ++y) {
                            if ((f2[l][k] & (1 << x)) && (f2[k + 1][r] & (1 << y))) {
                                f2[l][r] |= f1[x][y];
                            }
                        }
                    }
                }

                if (f2[l][r] & (1 << S))
                    f[l][r] = 1;
            }
        }

        if (f[1][n] == inf) cout << "NIE\n";
        else cout << f[1][n] << '\n';
    }

    system("pause");
    return 0;
}