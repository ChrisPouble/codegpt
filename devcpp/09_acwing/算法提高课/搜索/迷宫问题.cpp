#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
const int N = 1010;
PII pre[N][N]; //存储当前位置的前驱
bool st[N][N]; //表示当前位置的状态，若已用则为true,反之为false.
int n, c[N][N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void bfs() {
    queue <PII> q;
    q.push({n, n});
    st[n][n] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i];
            if(x >= 1 && x <= n && y >= 1 && y <= n && c[x][y] == 0 && !st[x][y]) {
                st[x][y] = 1;
                q.push({x, y});
                pre[x][y] = t; //存储一下当前合理位置的前驱,即该位置由哪个位置引入
            }
        }
    }

    //打印方案 
    int x = 1, y = 1;
    while (x != n || y != n) { //当 x = y = n 时,循环截止, 因为下标 n 为第一个元素，它没有前驱
        cout << x << ' ' << y << endl;
        auto t = pre[x][y];
        x = t.x, y = t.y;
    }
    cout << n << ' ' << n << endl;//单独打印第一个元素的下标

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    bfs();
    return 0;
}
