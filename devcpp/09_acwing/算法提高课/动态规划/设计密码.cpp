#include <bits/stdc++.h>
#define maxn 55
#define mod 1000000007
using namespace std;

int n, len, ans, ne[maxn], f[maxn][maxn];
char s[maxn];
void init() {
    for (int i = 2, j = 0; i <= len; i++) {
        while(j > 0 && s[j + 1] != s[i]) j = ne[j];
        if(s[j + 1] == s[i]) j++;
        ne[i] = j;
    }
}

signed main() {
    cin >> n >> (s + 1);
    len = strlen(s + 1);
    init();
    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < len; j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                int u = j;
                while(u > 0 && s[u + 1] != c) u = ne[u];
                if(s[u + 1] == c) u++;
                f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }
        }
    for (int i = 0; i < len; i++) ans = (ans + f[n][i]) % mod;
    cout << ans << endl;
    return 0;
}
