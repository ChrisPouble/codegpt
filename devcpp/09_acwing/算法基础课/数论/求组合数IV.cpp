#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#define maxn 5010
using namespace std;

int a, b, k, sum[maxn], prime[maxn], is_prime[maxn];
struct Int {
    int len, a[510];
    Int(string s) {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= s.size(); i++)
            a[i] = s[s.size() - i] - 48;
        len = s.size();
    }
    int& operator[](int i) { return a[i]; }
    void Cout() {
        if (a[len + 1] != 0) len++;
        for (int i = len; i >= 1; i--)
            cout << a[i];
        cout << endl;
    }
};

Int operator*(Int a, int b) {
    Int c("0");
    c.len = a.len + 10;
    for (int i = 1; i <= a.len; i++) c[i] = a[i] * b;
    for (int i = 1; i <= c.len; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c[c.len] == 0) c.len--;
    return c;
}

void is_primes(int x) {
	is_prime[1] = 1;
	for (int i = 2; i <= x; i++) {
		if(!is_prime[i]) prime[++k] = i;
		for (int j = 1; prime[j] * i <= x; j++) {
			is_prime[prime[j] * i] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int get(int n, int b) {
	int res = 0;
	while(n) {
		res += n / b;
		n /= b;
	}
	return res;
}

signed main() {
	cin >> a >> b;
	is_primes(a);
	for (int i = 1; i <= k; i++) {
		int x = prime[i];
		sum[i] = get(a, x) - get(b, x) - get(a - b, x);
	}
	Int ans("1");
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= sum[i]; j++)
			ans = ans * prime[i];
	ans.Cout();
	return 0;
}
