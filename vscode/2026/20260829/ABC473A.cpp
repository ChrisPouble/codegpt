#include <bits/stdc++.h>
using namespace std;

int n, a[110];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    long long ans = 0;
    for (int i = (n + 2) / 2; i <= n; i++)
        ans += a[i];
    
    cout << ans << endl;
    return 0;
}