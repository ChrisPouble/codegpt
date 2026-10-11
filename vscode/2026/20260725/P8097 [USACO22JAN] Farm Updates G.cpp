#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m;
int ans[N], act[N];
bool vis[N];
int eid, stat[N];
pair<int, int> q[N], e[N];
vector<int> linker[N];

void dfs(int x, int t) {
    vis[x] = 1;
	if (!ans[x]) ans[x] = t;
    for (auto v : linker[x]) {
        if (vis[v]) continue;
        act[v] |= act[x];
        dfs(v, t);
    }
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
		act[i] = 1;
    
    for (int i = 1, x, y; i <= m; i++) {
        string s; cin >> s;
        switch (s[0]) {
	        case 'A' :
    	        cin >> x >> y;
        	    e[++eid] = make_pair(x, y);
            	stat[eid] = 1;
    	        break;
        	case 'R' :
            	cin >> x;
	            q[i] = make_pair(1, x);
    	        stat[x] = 0;
        	    break;
        	case 'D' :
            	cin >> x;
	            act[x] = 0;
    	        q[i] = make_pair(2, x);
        	    break;
        }
    }
    
    for (int i = 1; i <= eid; i++) {
        if (!stat[i]) continue;
        linker[e[i].first].push_back(e[i].second);
        linker[e[i].second].push_back(e[i].first);
    }
    
    for (int i = 1; i <= n; i++)
        if (act[i] && !vis[i])
			dfs(i, m);
    
    for (int i = m; i >= 0; i--) {
        int x, y;
        switch (q[i].first) {
        	case 1:
	            x = e[q[i].second].first, y = e[q[i].second].second;
    	        linker[x].push_back(y), linker[y].push_back(x);
        	    if (act[x]) dfs(x, i - 1);
            	if (act[y]) dfs(y, i - 1);
	            break;
    	    case 2:
        	    x = q[i].second;
        	    act[x] = 1;
            	dfs(x, i - 1);
            	break;
        }
    }
    
    for (int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	
    return 0;
}