#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, y, pts;
};

int w, h, num;
char c;
bool a[305][305], vis[305][305];
queue<node> q;
bool judge() {
    for (int i = 1; i <= h * 2 + 1; i++)
        for (int j = 1; j <= w * 2 + 1; j++)
            if (!a[i][j] && !vis[i][j]) return false;
    return true;
}

int main() {
    cin >> w >> h;
    for (int i = 1; i <= h * 2 + 1; i++) {
        for (int j = 1; j <= w * 2 + 1; j++) {
            cin >> c;
            if (c != ' ' && c != '+' && c != '-' && c != '|') cin >> c;
            if (c != ' ') a[i][j] = true; //如果不是空格，则说明这个不能走
        }
    }
    for (int i = 1; i <= h * 2 + 1; i++) {
        for (int j = 1; j <= w * 2 + 1; j++) {
            if (!a[i][j] && (i == 1 || j == 1 || i == h * 2 + 1 || j == w * 2 + 1)) {
                num++;
                q.push({ i, j, 1 });
            }
            if (num == 2) break;
        }
    }
    while (!q.empty()) {
        node tmp = q.front();
        q.pop();
        if (vis[tmp.x][tmp.y] || a[tmp.x][tmp.y]) continue;
        vis[tmp.x][tmp.y] = true;
        if (judge()) {
            cout << tmp.pts / 2 << endl;
            return 0;
        }
        tmp.pts++;
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
        tmp.x++;
    }
    return 0;
}