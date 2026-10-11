#include <bits/stdc++.h>
#define lli long long int
using namespace std;
struct xs {
    lli x, y, step;
} tmp;
lli w, h, num = 0;
char c;
//a true表示墙，false 表述路
bool a[305][305], vis[305][305];
queue<xs> q;
bool judge() {
    for (lli i = 1; i <= h * 2 + 1; i++) {
        for (lli j = 1; j <= w * 2 + 1; j++) {
            if (!a[i][j] && !vis[i][j])
                return false;
        }
    }
    return true;
}
int main() {
    scanf("%lld%lld", &w, &h);
    for (lli i = 1; i <= h * 2 + 1; i++) {
        for (lli j = 1; j <= w * 2 + 1; j++) {
            scanf("%c", &c);
            if (c != ' ' && c != '+' && c != '-' && c != '|')
                scanf("%c", &c);
            if (c != ' ')
                a[i][j] = true;
        }
    }
    for (lli i = 1; i <= h * 2 + 1; i++) {
        for (lli j = 1; j <= w * 2 + 1; j++) {
            if (!a[i][j] && (i == 1 || j == 1 || i == h * 2 + 1 || j == w * 2 + 1)) {
                num++;
                tmp = { i, j, 1 };
                q.push(tmp);
            }
            if (num == 2)
                break;
        }
    }
    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (vis[tmp.x][tmp.y] || a[tmp.x][tmp.y])
            continue;
        vis[tmp.x][tmp.y] = true;
        if (judge()) {
            printf("%lld", tmp.step / 2);
            return 0;
        }
        tmp.step++;
        tmp.x++;
        q.push(tmp);
        tmp.x--;
        tmp.y++;
        q.push(tmp);
        tmp.y--;
        tmp.x--;
        q.push(tmp);
        tmp.x++;
        tmp.y--;
        q.push(tmp);
    }
    return 0;
}