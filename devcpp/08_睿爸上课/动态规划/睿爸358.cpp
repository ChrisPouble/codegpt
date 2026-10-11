#include <bits/stdc++.h>
#define maxn 4557430888798830399
using namespace std;

long long ans, f[110][100010], w[110], n, s;
int main() {
    cin >> s >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= n; i++) f[i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= s; j++) {
            f[i][j] = f[i - 1][j]; //先赋值，如果下面的if语句没有跑，那就完了 
            if (j >= w[i] && f[i][j - w[i]] != maxn) //如果总量够，并且能凑成j-w[i]，则开始赋值 
                f[i][j] = min(f[i][j], f[i][j - w[i]] + 1); //取最大值 
        }
	if(f[n][s] != maxn) cout << f[n][s] << endl;
	else cout << 0 << endl;
    return 0;
}
