#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, ans, a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int maxx = 0, minx = 1e9;
    for (int i = 1; i <= n; i++) {
        maxx = max(a[i], maxx);
        minx = min(a[i], minx);

        ans += maxx + minx;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}