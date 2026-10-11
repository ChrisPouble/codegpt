#include <bits/stdc++.h>
using namespace std;

int n, a[10];
void dfs(int x, int last, int sum) {
    if(sum == n) {
        cout << a[1];
        for (int i = 2; i <= x; i++)
            cout << "+" << a[i];
        cout << endl;
    }
    for (int i = last; i < n; i++) {
        if(i + sum > n) break;
        a[x + 1] = i;
        dfs(x + 1, i, sum + i);
        a[x + 1] = 0;
    }
}

int main() {
    freopen("brick.in", "r", stdin);
    freopen("brick.out", "w", stdout);
    cin >> n;
    dfs(0, 1, 0);
    return 0;
}