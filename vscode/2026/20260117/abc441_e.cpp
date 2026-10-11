#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;
const int P = 5e5 + 3; 

int n, a[N];
int sum[N], tree[N];
string s;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int d) {
    while (x <= P + n) {
        tree[x] += d;
        x += lowbit(x);
    }
}

int query(int x) {
    int res = 0;
    while (x) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'A') a[i] = 1;
        if (s[i - 1] == 'B') a[i] = -1;
        if (s[i - 1] == 'C') a[i] = 0;
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0; add(P, 1);
    for (int i = 1; i <= n; i++) {
        ans += query(sum[i] + P - 1);
        add(sum[i] + P, 1);
    }

    cout << ans << endl;

	return 0;
}