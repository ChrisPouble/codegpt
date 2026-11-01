#include <bits/stdc++.h>
using namespace std;

int a[110];

int main() {
    int n, K; cin >> n >> K;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] < K && a[i] > K)
            ans++;
        else if (a[i - 1] > K && a[i] < K)
            ans++;
    }

    for (int i = 1; i <= n; i++)
        if (a[i] == K) ans++;

    cout << ans << endl;
    
    return 0;
}