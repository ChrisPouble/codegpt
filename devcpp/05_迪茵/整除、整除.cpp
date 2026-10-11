#include <bits/stdc++.h>
using namespace std;

long long n;
map<long long, long long>m;
long long up(long long x) {
	if(x % 2) return x / 2 + 1;
	return x / 2;
}

long long down(long long x) {
	return x / 2;
}

long long dg(long long x) {
	if(m[x]) return m[x];
	if(x < 2) return 0;
	return m[x] = dg(up(x)) + dg(down(x)) + x;
}

int main() {
	cin >> n;
	cout << dg(n) << endl;
	return 0;
}
