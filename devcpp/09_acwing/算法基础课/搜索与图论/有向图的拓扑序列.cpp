#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, inv[maxn];
vector<int>linker[maxn];
void bfs() {
    queue<int>q, ans;
    for (int i = 1; i <= n; i++)
        if(!inv[i]) q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans.push(x);
        for (auto v:linker[x]) {
            inv[v]--;
            if(inv[v] == 0) q.push(v);
        }
    }
    if(ans.size() != n) {
        cout << -1 << endl;
        return ;
    }
    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, w; i <= m; i++) scanf("%d%d", &x, &y), linker[x].push_back(y), inv[y]++;
	bfs();
	return 0;
}
