#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

struct node {
    int x, pts;
};

int n, m, vis[maxn];
vector<int>linker[maxn];
int main() {
    cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) cin >> x >> y, linker[x].push_back(y);
    queue<node>q;
    q.push({1, 0}), vis[1] = 1;
    while(!q.empty()) {
        int x = q.front().x;
        int pts = q.front().pts;
        q.pop();
        if(x == n) {
            cout << pts << endl;
            return 0;
        }
        for (auto v:linker[x]) {
            if(vis[v]) continue;
            q.push({v, pts + 1});
            vis[v] = 1;
        }
    }
    cout << -1 << endl;
    return 0;
}
