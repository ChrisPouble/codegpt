#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int n;
char c[maxn][maxn];
int dis[maxn][maxn];
struct node {
	int u, v;
};

queue<node> q;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> (c[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        q.push({i, i});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && c[i][j] != '-') {
                dis[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty()) {
        int u = q.front().u;
		int v = q.front().v;
		q.pop();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][j] == -1 && c[i][u] == c[v][j] && c[i][u] != '-') {
                    dis[i][j] = dis[u][v] + 2;
                    q.push({i, j});
                }
    }
    for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= n; j++)
            cout << dis[i][j] << ' ';
    return 0;
}
