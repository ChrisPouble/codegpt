#include <bits/stdc++.h>
using namespace std;

int n;
struct Point{
    int be, end, monney;
};

Point a[10010];
int pre[10010], f[10010];
bool cmt(Point x, Point y) {
    if(x.end < y.end) return true;
    else return false;
}

int main() {
    freopen("brick.in", "r", stdin);
    freopen("brick.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].be >> a[i].end >> a[i].monney;
    sort(a + 1, a + n + 1, cmt);
    pre[1] = 0;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if(a[i].be >= a[j].end) pre[i] = j;
    for (int i = 1; i <= n; i++) {
        if(a[i].monney + f[pre[i]] > f[i - 1]) f[i] = a[i].monney + f[pre[i]];
        else f[i] = f[i - 1];
    }
    cout << f[n] << endl;
    return 0;
}