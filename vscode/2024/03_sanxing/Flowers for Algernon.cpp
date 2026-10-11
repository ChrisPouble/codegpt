#include<bits/stdc++.h>
using namespace std;

char c[210][210];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
struct zb{
    int x, y, sum;
};
bool a[210][210];

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    int T; cin >> T;
    while(T--) {
        memset(a, false, sizeof(a));
        int n, m; cin >> n >> m;
        int si, sj, ei, ej;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
                if(c[i][j] == 'S') si = i, sj = j;
                if(c[i][j] == 'E') ei = i, ej = j;
            }
        queue<zb>q;
        zb temp;
        temp.x = si, temp.y = sj, temp.sum = 0;
        q.push(temp);
        a[si][sj] = true;
        bool is = false;
        while(!q.empty()) {
            if(is) break;
            int x = q.front().x;
            int y = q.front().y;
            int sum = q.front().sum;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = dx[i] + x, ty = dy[i] + y;
                if(tx < 1 || tx > n || ty < 1 || ty > m || c[tx][ty] == '#' || a[tx][ty] == true) continue;
                if(tx == ei && ty == ej) {
                    cout << sum + 1 << endl;
                    is = true;
                    break;
                }
                zb t;
                t.x = tx, t.y = ty, t.sum = sum + 1;
                q.push(t);
                a[tx][ty] = true;
            }
        }
        if(!is) cout << "oop!" << endl;
    }
    return 0;
}