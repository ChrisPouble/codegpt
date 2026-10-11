#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N], cnt[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;

    int sum = 0;
    for (int i = 0; i <= m; i++)
        sum += (cnt[i] > 0);

    cout << (sum != n ? "No" : "Yes") << endl;
    cout << (sum != m ? "No" : "Yes") << endl;
    
    system("pause");
    return 0;
}