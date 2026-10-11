#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3e5 + 10;

int n, k, x;
int a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
    cin >> n >> k >> x;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if (sum >= x) {
            cout << i << endl;
            return 0;
        }
    }

	return 0;
}