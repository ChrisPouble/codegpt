// Problem: CF1764D Doremy's Pegging Game
// Contest: Codeforces - Global Round 24
// URL: https://codeforces.com/problemset/problem/1764/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// 
// Powered by ChrisPang

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e3 + 10;

int n, P;

ll ksm(ll a, ll b) {
	ll res = 1ll;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a, b >>= 1;
	}
	return res;
}

ll fac[N], c[N][N];

int main() {
	cin >> n >> P;
	
    fac[0] = 1;
    for (int i = 1; i < N; i++)
		fac[i] = fac[i - 1] * i % P;
	
	for (int i = 0; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
    }
	
	ll ans = 0;
	for (int i = n / 2 + 1; i <= n - 1; i++) {
        for (int j = i - 1; j <= n - 2; j++) {
            ans = (ans + fac[j - 1] * (n / 2 + n / 2 - i + 1) % P * c[n - i - 1][j - i + 1]) % P;
        }
    }
    
    if (n % 2 == 0) ans = (ans + fac[n - 2]) % P;
    ans = ans * n % P;
    
    cout << ans << endl;
    
    return 0;
}