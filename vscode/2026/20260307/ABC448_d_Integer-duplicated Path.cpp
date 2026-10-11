#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], ans[N];
map<int, int> vis;
vector<int> linker[N];

void dfs(int x, int fa) {
    ans[x] |= (vis[a[x]] >= 1);
    vis[a[x]]++;

    for (int v : linker[x]) {
        if (v == fa) continue;

        ans[v] |= ans[x];
        dfs(v, x);
    }

    vis[a[x]]--;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1, x, y; i < n; i++) {
    	cin >> x >> y;
    	linker[x].push_back(y);
    	linker[y].push_back(x);
	}

    dfs(1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}
