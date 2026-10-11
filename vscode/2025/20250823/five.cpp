#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 1e3 + 10;

int T;
int n, ans, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);
	
    if (a[1] != 0) {
        cout << 0 << endl;
        return ;
    }
    
    for (int i = 1; i <= n; i++) {
        if (a[i] - a[i - 1] > 1) {
            cout << a[i - 1] + 1 << endl;
            return ;
        }
    }

    cout << a[n] + 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    while (T--) solve();

    // system("pause");
    return 0;
}