#include <bits/stdc++.h>
#define maxn 2000010
#define int long long
using namespace std;

int n, p[maxn >> 1], d[maxn >> 1], s[maxn], q[maxn], h[maxn];
bool f[maxn];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i], &d[i]);
    for (int i = 1; i <= n; i++) s[i] = s[i + n] = p[i] - d[i];
    for (int i = 1; i <= 2 * n; i++) s[i] += s[i - 1];
    int hh = 0, tt = -1;
    for (int i = 2 * n; i >= 1; i--) {
        if(hh <= tt && q[hh] >= i + n) hh++; //超出[i, i + n - 1]
        while(hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
        if(i <= n && s[q[hh]] >= s[i - 1]) f[i] = 1; //顺时针
    }
    d[0] = d[n];
    for (int i = n; i >= 1; i--) h[i] = h[i + n] = p[i] - d[i - 1];
    for (int i = 2 * n; i >= 1; i--) h[i] += h[i + 1];
    hh = 0, tt = -1;
    for (int i = 1; i <= 2 * n; i++) {
        if(hh <= tt && q[hh] <= i - n) hh++; //超出[i - n + 1, i]
        while(hh <= tt && h[q[tt]] >= h[i]) tt--;
        q[++tt] = i;
        if(i > n && h[q[hh]] >= h[i + 1]) f[i - n] = 1; //顺时针
    }
    for (int i = 1; i <= n; i++)
        if(f[i]) printf("TAK\n");
        else printf("NIE\n");
    return 0;
}
