#include <bits/stdc++.h>
using namespace std;

int n, m, sum, ans, a[100010];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        if(sum > m) ans++, sum = a[i];
    }
    cout << ans + 1 << endl;
    return 0;
}