#include <bits/stdc++.h>
#define inf 1000000000
#define maxn 1010
using namespace std;

int n, m, s, f[maxn][maxn]; //a的1~i转成b的1~j
char a[maxn][maxn], b[maxn];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    while(m--) {
        int res = 0;
        scanf("%s%d", b + 1, &s);
        for (int k = 1; k <= n; k++) {
            int lena = strlen(a[k] + 1), lenb = strlen(b + 1);
            for (int i = 1; i <= lena; i++) 
                for (int j = 1; j <= lenb; j++) 
                    f[i][j] = inf;
            for (int i = 1; i <= lena; i++) f[i][0] = i;
            for (int i = 1; i <= lenb; i++) f[0][i] = i;
            for (int i = 1; i <= lena; i++) {
                for (int j = 1; j <= lenb; j++) {
                    f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1); //增和删
                    if (a[k][i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]); //不改
                    else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1); //改
                }
            }
            res += f[lena][lenb] <= s;
        }
        cout << res << endl;
    }
    return 0;
}
