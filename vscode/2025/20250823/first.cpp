#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, ans, a[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] < a[j]) ans++;

    cout << ans << endl;
    
    system("pause");
    return 0;
}