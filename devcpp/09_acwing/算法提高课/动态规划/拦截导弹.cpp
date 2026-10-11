#include <bits/stdc++.h>
using namespace std;

int n = 1, ans, a[5010], f[5010];
vector<int> vec;
bool is(int x) {
    for (int j = 0; j < vec.size(); j++)
        if (vec[j] >= x) {
            vec[j] = x;
            return true;
        }
    return false;
}

int main() {
    while (cin >> a[n]) n++;
    n--;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    vec.push_back(a[1]);
    for (int i = 2; i <= n; i++)
        if (!is(a[i]))
            vec.push_back(a[i]);
    cout << vec.size() << endl;
    return 0;
}
