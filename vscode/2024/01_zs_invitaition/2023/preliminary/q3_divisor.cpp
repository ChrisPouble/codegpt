#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1010];
int dg(long long x, long long y) {
    if(y == 0) return x;
    return dg(y, x % y);
}

long long divisor() {
    long long sum;
    for (int i = 1; i <= n - 1; i++) {
        if(a[i] > a[i + 1]) sum = dg(a[i], a[i + 1]);
        else sum = dg(a[i + 1], a[i]);
    }
    return sum;
}

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long maxd = divisor();
    long long pingfang = sqrt(maxd);
    for (int i = 2; i <= pingfang; i++) {
        if(maxd % i == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << maxd << endl;
    return 0;
}