#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool P(int a, int b) {
    int ic = sqrt(a * a + b * b);
    double dc = sqrt(a * a + b * b);
    if(ic * 1.0 != dc || a + b + ic + 1 > n) return false;
    else return true;
}

bool vis[4000][5500];
int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = i + 1; j <= n / 2; j++) {
            if(P(i, j)) {
                ans++;
                cout << i << " " << j << " " << sqrt(i * i + j * j) << endl;
            }
        }
    }
    cout << ans  << endl;
    return 0;
}