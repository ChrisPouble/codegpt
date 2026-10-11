#include <bits/stdc++.h>
using namespace std;

int n, x, y, k, a[50][50];
int main() {
    cin >> n;
    x = 1, y = n / 2 + 1, k = 1, a[1][n / 2 + 1] = 1;
    for (int i = 2; i <= n * n; i++) {
        if(x == 1 && y != n) x = n, y++;
        else if(x != 1 && y == n) x--, y = 1;
        else if(x == 1 && y == n) x++;
        else if(x != 1 && y != n) {
            if(a[x - 1][y + 1] == 0) x--, y++;
            else x++;
        }
        a[x][y] = ++k;
    }
    for (int i = 1; i <= n; i++, puts(" "))
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
    return 0;
}