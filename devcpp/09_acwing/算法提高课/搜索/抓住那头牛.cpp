#include <bits/stdc++.h>
#define maxn 200
using namespace std;

int n, m;
map<int, int>vis;
struct node {
    int x, pts;
};

void bfs() {
    queue<node>q;
    q.push({n, 0});
    vis[n] = 1;
    while (!q.empty()) {
        int x = q.front().x;
        int pts = q.front().pts;
        q.pop();
        if (x == m) {
            cout << pts << endl;
            exit(0);
        }
        int tx1 = x + 1;
        int tx2 = x - 1;
        int tx3 = 2 * x;
        if (!vis[tx1]) q.push({tx1, pts + 1}), vis[tx1] = 1;
        if (tx2 >= 0 && !vis[tx2]) q.push({tx2, pts + 1}), vis[tx2] = 1;
        if (tx3 <= 2 * m && !vis[tx3]) q.push({tx3, pts + 1}), vis[tx3] = 1;
    }
}

signed main() {
	cin >> n >> m;
	if (n >= m) cout << n - m << endl;
	else bfs();
	return 0;
}
