#include <bits/stdc++.h>
#define int __int128
#define maxn 55
using namespace std;

#define typeOfReadAndWrite __int128
typeOfReadAndWrite read() {
	typeOfReadAndWrite x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(typeOfReadAndWrite x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}


int n, w[maxn], f[maxn][maxn];
signed main() {
    n = read();
    for (int i = 1; i <= n; i++) w[i] = read();
    for (int l = n; l >= 1; l--)
        for (int r = l + 2; r <= n; r++) {
            f[l][r] = 1e30;
            for (int k = l + 1; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
        }
    write(f[1][n]);
    return 0;
}
