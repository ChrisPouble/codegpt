#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[1000], b[1000];
int is[15][15];
int End[15];

vector<int> ans;

bool cmp(int x, int y) {
    return End[x] < End[y];
}

int main() {
    cin >> n >> m >> k;
    
    for (int i = 1; i <= k; i++) {
        cin >> a[i] >> b[i];
        is[a[i]][b[i]] = 1;
        End[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++)
            sum += is[i][j];
        if (sum == m) ans.push_back(i);
    }

    sort(ans.begin(), ans.end(), cmp);

    for (int v : ans) cout << v << " ";

    system("pause");
    return 0;
}