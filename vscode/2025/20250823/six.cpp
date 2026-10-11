#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int N = 500 + 10;

int n, ans;
int f[N][N];
string s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    n = s.size(), s = " " + s;

    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    
    for (int i = 1; i < n; i++)
        f[i][i + 1] = (s[i] == s[i + 1]);

    for (int l = n; l >= 1; l--) {
        for (int r = l + 2; r <= n; r++) {
            f[l][r] = (s[l] == s[r]) && (f[l + 1][r - 1]);
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            ans += f[i][j];

    cout << ans << endl;

    // system("pause");
    return 0;
}