#include <bits/stdc++.h>
using namespace std;

long long n, ans, a[100010];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if(a[i] > a[i - 1]) ans += a[i] - a[i - 1];
    cout << ans << endl;
    return 0;
}