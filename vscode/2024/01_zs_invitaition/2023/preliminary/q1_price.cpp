#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    int n, m; cin >> n >> m;
    double ans = 0;
    if (n > 100) ans = n * m * 0.7;
    else if(n > 50) ans = n * m * 0.8;
    else if(n > 10) ans = n * m * 0.9;
    else ans = n * m;
    printf("%.2f", ans);
    return 0;
}