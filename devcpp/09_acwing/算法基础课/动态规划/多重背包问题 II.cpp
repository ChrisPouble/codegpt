#include <bits/stdc++.h>
#define maxn 2010
using namespace std;

int n, V, cnt, v[maxn * 12], w[maxn * 12], f[maxn];
signed main() {
	cin >> n >> V;
	for (int i = 1; i <= n; i++) {
	    int a, b, c, k = 1;
	    cin >> a >> b >> c;
	    while(k <= c) {
	        cnt++;
	        v[cnt] = a * k;
	        w[cnt] = b * k;
	        c -= k, k *= 2;
	    }
	    if(c > 0) {
	        cnt++;
	        v[cnt] = a * c;
	        w[cnt] = b * c;
	    }
	}
	for (int i = 1; i <= cnt; i++)
		for (int j = V; j >= v[i]; j--)
			if(j >= v[i]) f[j] = max(f[j], f[j - v[i]] + w[i]);
	cout << f[V] << endl;
	return 0;
}
