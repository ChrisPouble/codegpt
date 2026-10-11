#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

long long n, a[N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    int l = -1, r = -1, now = 0;
    for (int i = 1; i < n; i++) {
        if (a[i + 1] >= 0) {
            (abs(a[i]) <= abs(a[i + 1]) ? 
                l = i, r = i : 
                l = r = i + 1
            ); break;
        }
    }

    if (l == -1 && r == -1) l = r = n;

    long long ans = abs(now - a[l]); now = a[l];
    while (l > 1 || r < n) {
        // cout << now << " ";
        if (l <= 1) { ans += abs(now - a[r + 1]), now = a[r + 1], r++; continue; }
        else if (r >= n) { ans += abs(now - a[l - 1]), now = a[l - 1], l--; continue; }

        if (abs(now - a[l - 1]) <= abs(now - a[r + 1])) ans += abs(now - a[l - 1]), now = a[l - 1], l--;
        else ans += abs(now - a[r + 1]), now = a[r + 1], r++;
    }

    cout << ans << endl;

    return 0;
}