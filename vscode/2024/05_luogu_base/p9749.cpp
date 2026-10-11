#include <bits/stdc++.h>
using namespace std;

long long n, d, x, money = 1e9, s, car, ans;
long long v[100010];

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
        cin >> v[i];
    cin >> x;
    money = x;
    int need_s = 0, car_s = 0;
    for (int i = 1; i <= n - 1; i++) {
        cin >> x;
        need_s += v[i];
        if(money > x || i == n - 1) {
            int L = (need_s - car_s + d - 1) / d;
            ans += L * money;
            car_s += L * d;
            money = x;
        }
    }
    cout << ans << endl;
    return 0;
}

int main1() {
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
        cin >> v[i];
    for (int i = 1; i <= n - 1; i++) {
        cin >> x;
        money = min(money, x);
        s += v[i];
        if(s > 0) {
            ans += (s+d-1)/d* money;
            s -= (s+d-1)/d * d;
        }
    }
    cout << ans << endl;
    return 0;
}