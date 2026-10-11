#include <bits/stdc++.h>
using namespace std;

int n, Size, k[1010], a[1010], yl, xz;
bool vis[1000010];
int dfs1(vector<int>v, int l, int r) {
    if(l >= r) return 1;
    int sum = 1, i;
    for (i = l + 1; i < r; i++)
        if(v[i] == v[i - 1]) sum++;
        else break;
    return max(sum, dfs1(v, i, r));
}

int dfs2(int l, int r) {
    if(l >= r) return 1;
    int sum = 1, i;
    for (i = l + 1; i <= r; i++)
        if(a[i] == a[i - 1]) sum++;
        else break;
    return max(sum, dfs2(i, r));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(vis[a[i]] == 0) {
            Size++;
            k[Size] = a[i];
            vis[a[i]] = 1;
        }
    }
    yl = dfs2(1, n);
    for (int i = 1; i <= Size; i++) {
        vector<int> v;
        for (int j = 1; j <= n; j++)
            if(a[j] != k[i]) v.push_back(a[j]);
        xz = max(xz, dfs1(v, 0, v.size()));
    }
    cout << xz - yl << endl;
    return 0;
}