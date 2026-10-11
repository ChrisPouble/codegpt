#include <bits/stdc++.h>
#define inf 1000000000
#define maxn 1010
using namespace std;

int lena, lenb, f[maxn][maxn]; //a的1~i转成b的1~j
char a[maxn], b[maxn];
int main() {
    scanf("%d%s", &lena, a + 1);
    scanf("%d%s", &lenb, b + 1);
    for (int i = 1; i <= lena; i++) 
        for (int j = 1; j <= lenb; j++) 
            f[i][j] = inf;
    for (int i = 1; i <= lena; i++) f[i][0] = i;
    for (int i = 1; i <= lenb; i++) f[0][i] = i;
    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1); //增和删
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]); //不改
            else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1); //改
        }
    }
    printf("%d\n", f[lena][lenb]);
    return 0;
}
