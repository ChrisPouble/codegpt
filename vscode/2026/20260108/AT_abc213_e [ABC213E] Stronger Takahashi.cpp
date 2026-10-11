#include <bits/stdc++.h>
#define maxn 510
using namespace std;

int H, W, dis[maxn][maxn];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int fx[25] = { 0, 0, 0, 0, 1, 1, 1, 1, -1, -1, -1, -1, -2, -2, -2, 2, 2, 2, 1, -1 };
int fy[25] = { 1, 2, -1, -2, 1, 2, -1, -2, 1, 2, -1, -2, 1, 0, -1, 1, 0, -1, 0, 0 };
struct node {
    int x, y;
};

char c[maxn][maxn];
bool is(int x, int y) {
    if (x < 1 || x > H || y < 1 || y > W)
        return 0;
    return 1;
}

void bfs(int sx, int sy) {
    memset(dis, 0x3f, sizeof(dis));
    deque<node> q;
    dis[sx][sy] = 0;
    q.push_back({ sx, sy });
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (is(tx, ty) && dis[tx][ty] > dis[x][y] && c[tx][ty] == '.') {
                dis[tx][ty] = dis[x][y];
                q.push_front({ tx, ty });
            }
        }
        for (int i = 0; i < 20; i++) {
            int tx = x + fx[i], ty = y + fy[i];
            if (is(tx, ty) && dis[tx][ty] > dis[x][y] + 1) {
                dis[tx][ty] = dis[x][y] + 1;
                q.push_back({ tx, ty });
            }
        }
    }
}

int main() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) cin >> c[i][j];
    bfs(1, 1);
    cout << dis[H][W] << endl;
    return 0;
}