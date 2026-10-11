#include <iostream>
using namespace std;

const int maxn = 1e5 + 10;
long long n, t, ans, x[maxn], y[maxn], z[maxn];
int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i] >> z[i];
    for (int i = 1; i <= n; i++) {
        int sum = 0, l = 0, r = 1e5, mid;
        while (l < r) {
            mid = (l + r) / 2;
            long long temp1 = x[i] * mid;
            long long temp2 = y[i] * mid;
            long long temp3 = z[i] * (mid * (mid - 1) / 2);
            long long temp = temp1 + temp2 + temp3;
            if (temp < t) l = mid + 1;
            else r = mid - 1;
        }
        if (x[i] * mid + y[i] * mid + z[i] * (mid * (mid - 1) / 2) + x[i] <= t &&
            x[i] * mid + y[i] * mid + z[i] * (mid * (mid - 1) / 2) + x[i] + y[i] > t)
            sum += t - (x[i] * mid + y[i] * mid + z[i] * (mid * (mid - 1) / 2) + x[i]);
        sum += y[i] * mid + z[i] * (mid * (mid - 1) / 2);
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}
/*
1 233333
233 233 233
*/