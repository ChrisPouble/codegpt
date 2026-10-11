#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans = 2e8, dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char c[110][110];
bool a[110][110];
int h = 1, t = 0, q1[11000], q2[11000], q3[11000];
int me(int dx, int dy) {

    q1[++t] = dx, q2[t] = dy, q3[t] = 0;
    a[dx][dy] = true;
    while (h <= t) {
        int x = q1[h], y = q2[h], sum = q3[h];
        h++;
        for (int i = 0; i < 4; i++) {
            int tx = x + dxy[i][0], ty = y + dxy[i][1];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || c[tx][ty] == '#' || a[tx][ty]) continue;
            if (c[tx][ty] == 'T') ans = min(ans, sum + 1);
            if (c[tx][ty] == '.') {
                q1[++t] = tx, q2[t] = ty, q3[t] = sum + 1;
                a[tx][ty] = true;
            }
        }
    }
    return ans;
    return 0;
}