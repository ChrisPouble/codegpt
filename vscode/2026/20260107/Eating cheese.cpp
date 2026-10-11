#include <bits/stdc++.h>
using namespace std;

const int N = 20;

struct node {
    double x, y;
} a[N];

int n;
double f[1 << N][N];

double work(int i, int j) {
    double xx1 = a[i].x, yy1 = a[i].y;
    double xx2 = a[j].x, yy2 = a[j].y;
    return sqrt((xx1 - xx2) * (xx1 - xx2) + (yy1 - yy2) * (yy1 - yy2));
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;
    
    int mst = 1 << n;
    for (int i = 1; i < mst; i++)
    	for (int j = 0; j < n; j++)
    		f[i][j] = 1e9;
    
    for (int i = 0; i < n; i++)
        f[1 << i][i] = work(n, i);
    
    for (int i = 1; i < mst; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) continue;
            for (int k = 0; k < n; k++) {
                if (!(i & (1 << k))) continue;
                int nst = i + (1 << j);
                f[nst][j] = min(f[i][k] + work(k, j), f[nst][j]);
            }
        }
    }

    double ans = 1e9;
    for (int i = 0; i < n; i++) 
        ans = min(ans, f[mst - 1][i]);
    
    printf("%.2f", ans);
    return 0;
}
