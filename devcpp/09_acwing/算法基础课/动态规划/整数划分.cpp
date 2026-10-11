#include <bits/stdc++.h>
#define maxn 1010
#define mod 1000000007
using namespace std;

int n, f[maxn];
int main() {
    cin >> n;
    f[0] = 1; //不选也是方案
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if(j >= i) f[j] = (f[j] + f[j - i]) % mod; //f[i][j] = f[i - 1][j] + f[i][j - i]
    printf("%d\n", f[n]);
    return 0;
}
