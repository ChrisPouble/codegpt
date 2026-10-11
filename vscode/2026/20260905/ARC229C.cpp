#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int n, a[N], b[N];
void solve(){
    cin >> n;

    int sum = 0, ans = 1e15;
    int lena = 0, lenb = 0;
    for (int i = 1, x; i <= n; i++) {
        cin >> x, sum += x;
        if (x & 1)
            a[++lena] = x;
        else
            b[++lenb] = x;
    }

    sort(a + 1, a + lena + 1); reverse(a + 1, a + lena + 1);
    sort(b + 1, b + lenb + 1); reverse(b + 1, b + lenb + 1);
    
    if (lena >= 2)
        ans = min(ans, sum - ((a[1] + a[2]) + 2 * (min(lena - 1, lenb))) / 2);
    
    if (lenb >= 2)
        ans = min(ans, sum - ((b[1] + b[2]) + 2 * (min(lena, lenb - 1))) / 2);
    
    if (lena >= 1 && lenb >= 1)
        ans = min(ans, sum - ((a[1] + b[1]) + 2 * (min(lena, lenb)) - 1) / 2);
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) solve();

    return 0;
}