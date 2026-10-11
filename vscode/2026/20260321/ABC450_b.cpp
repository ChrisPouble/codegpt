#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, dis[N][N];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> dis[i][j];

    int ans = 0;
    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
            for (int c = 1; c <= n; c++)
                if (dis[a][b] + dis[b][c] < dis[a][c]) 
                    ans = 1;
    
    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}