#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int qsum = 0, hsum = 0;
    for (int i = 1; i <= n; i++)
        hsum += a[i];
    
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        qsum += a[i], hsum -= a[i];
        ans = min(ans, abs(qsum - hsum));
    }

    cout << ans << endl;
    
    return 0;
}