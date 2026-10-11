#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, V, v[maxn][maxn], w[maxn][maxn], s[maxn], f[maxn];
signed main() {
	cin >> n >> V;
	for (int i = 1; i <= n; i++) {
	    cin >> s[i];
	    for (int j = 1; j <= s[i]; j++) cin >> v[i][j] >> w[i][j];
	}
	for (int i = 1; i <= n; i++)
		for (int j = V; j >= 1; j--)
		    for (int k = 1; k <= s[i]; k++)
			    if(j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
	cout << f[V] << endl;
	return 0;
}
