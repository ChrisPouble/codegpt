#include <bits/stdc++.h>
using namespace std;

int n, a[110];
map <int, int> cnt;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == -1) continue;
        ans += (cnt[a[i]] & 1) * a[i];
        cnt[a[i]] = -1;
    }
    
    cout << ans << endl;
    return 0;
}