#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node {
    int a, b, c;
} love[N];

int n, choose[N];

void solve() {
    for (int i = 1; i <= n; i++)
        choose[i] = 0;
    
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> love[i].a;
        cin >> love[i].b;
        cin >> love[i].c;
    }

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int res = 0;

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (love[i].a >= max(love[i].b, love[i].c))
            choose[i] = 1, cnt1++, res += love[i].a;
        else if (love[i].b >= max(love[i].a, love[i].c))
            choose[i] = 2, cnt2++, res += love[i].b;
        else if (love[i].c >= max(love[i].a, love[i].b))
            choose[i] = 3, cnt3++, res += love[i].c;
    }

    for (int i = 1; i <= n; i++) {
        if (cnt1 > n / 2 && choose[i] == 1)
            ans.push_back(love[i].a - max(love[i].b, love[i].c));
        if (cnt2 > n / 2 && choose[i] == 2)
            ans.push_back(love[i].b - max(love[i].a, love[i].c));
        if (cnt3 > n / 2 && choose[i] == 3)
            ans.push_back(love[i].c - max(love[i].a, love[i].b));
    }

    sort(ans.begin(), ans.end());

    int p = 0;
    while (cnt1 > n / 2) res -= ans[p++], cnt1--;
    while (cnt2 > n / 2) res -= ans[p++], cnt2--;
    while (cnt3 > n / 2) res -= ans[p++], cnt3--;

    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--) solve();

    return 0;
}