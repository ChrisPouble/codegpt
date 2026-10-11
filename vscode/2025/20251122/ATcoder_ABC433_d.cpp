#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

const int N = 2e5 + 10;

int n, m, a[N];
map<int, int> cnt[15];

int chris[15] = { 1 };

int work(int x) {
    int sum = 0;
    while (x) {
        sum++;
        x /= 10;
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    for (int i = 1; i <= 10; i++) {
    	chris[i] = chris[i - 1] * 10;
    	// cout << chris[i] << " ";
	}

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int p = 1; p <= 10; p++) {
        for (int i = 1; i <= n; i++) {
            int x = a[i] * chris[p];
            cnt[p][x % m]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int len = work(a[i]);
        ans += cnt[len][(m - a[i] % m) % m];
//        if (a[i] * chris[len] + )
//        cout << cnt[len][m - a[i] % m] << endl;
    }

    cout << ans << endl;

    return 0;
}
