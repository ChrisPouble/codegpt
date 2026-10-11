#include <bits/stdc++.h>
using namespace std;

int n, k, a[12];
vector<vector<int> > ans;

void dfs(int pos, int sum) {
    if (pos == 1) {
        a[1] = sum;
        ans.push_back(vector<int>(a + 1, a + n + 1));
        return ;
    }

    int lim = sum / pos;
    for (int val = 0; val <= lim; val++) {
        a[pos] = val;
        dfs(pos - 1, sum - pos * val);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    dfs(n, k);

    sort(ans.begin(), ans.end());

    for (auto seq : ans) {
        for (int v : seq)
            cout << v << " ";
        cout << '\n';
    }
    return 0;
}