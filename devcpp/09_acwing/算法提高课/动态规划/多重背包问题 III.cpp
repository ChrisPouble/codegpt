#include <bits/stdc++.h>
#define maxn 1010
#define maxm 20010
using namespace std;

int n, V, v[maxm], w[maxm], s[maxm], f[maxn][maxm];
int q[maxm], hh, tt;
signed main() {
	cin >> n >> V;
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];
	for (int i = 1; i <= n; i++)
    	for (int r = 0; r < v[i]; r++) {
    	    hh = 1, tt = 0;
    	    for (int j = r; j <= V; j += v[i]) {
	    	    while(hh <= tt && j - q[hh] > s[i] * v[i]) hh++;
	    	    while(hh <= tt && f[i - 1][j] >= f[i - 1][q[tt]] + (j - q[tt]) / v[i] * w[i]) tt--;
	    	    q[++tt] = j;
	    	    f[i][j] = f[i - 1][q[hh]] + (j - q[hh]) / v[i] * w[i];
		    }
    	}
	cout << f[n][V] << endl;
	return 0;
}
