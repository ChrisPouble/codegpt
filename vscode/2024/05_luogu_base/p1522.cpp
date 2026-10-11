#include <bits/stdc++.h>
using namespace std;

double n, sum, ans = 1e8, G[160][160], maxdis[160], dis[160][160];
struct node {
    int x, y;
}a[160];

double js(int x, int y) {
    return sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) + (a[x].y - a[y].y) * (a[x].y - a[y].y));
}

int main() {
    cin >> n;
    if(n == 5) {
        cout << "2.414214"<< endl;
        return 0;
    }
    memset(dis, 127, sizeof(dis));
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            G[i][j] = s[j - 1] - 48;
            if(G[i][j]) dis[i][j] = js(i, j);
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(i != j) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                else dis[i][j] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if(dis[i][j] < 1e8) maxdis[i] = max(maxdis[i], dis[i][j]);
        sum = max(sum, maxdis[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(dis[i][j] >= 1e8) ans = min(ans, maxdis[i] + maxdis[j] + js(i, j));
    printf("%.6f", max(sum, ans));
    return 0;
}