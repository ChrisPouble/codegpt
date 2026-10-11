#include <bits/stdc++.h>
using namespace std;

long long n, l, r, c, a[100010], b[100010];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    cin >> l >> r >> c;
    for (long long i = l; i <= r; i++) {
        for (long long j = 1; j <= n; j++)
            if(i - b[j] >= 0)
                if((i - b[j]) % a[j] == 0) c--;
        if(c <= 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}