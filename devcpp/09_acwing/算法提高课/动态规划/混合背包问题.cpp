#include <bits/stdc++.h>
#define maxn 1010
#define endl "\n"
using namespace std;

int n, cnt, V, v[maxn * 15], w[maxn * 15], f[maxn];
int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(c == -1) c = 1;
        else if(c == 0) c = 1000;
        int k = 1;
        while(c > k) {
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            c -= k, k *= 2;
        }
        if(c > 0) {
	        cnt++;
	        v[cnt] = a * c;
	        w[cnt] = b * c;
	    }
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = V; j >= 0; j--)
            if(j >= v[i]) f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[V] << endl;
    return 0;
}
