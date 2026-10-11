#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string, int> cnt;

    for (int i = 1; i <= n; i++) {
        string str; cin >> str;
        for (int j = 0; j < str.size(); j++)
            str[j] = (str[j] >= 'a' ? 'A' + str[j] - 'a' : str[j]);
        cnt[str]++;
    }

    int ans = 0;
    for (auto p : cnt) {
        if (p.second > ans) {
            ans = p.second;
        }
    }

    cout << ans << endl;

    return 0;
}