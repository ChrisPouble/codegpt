#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const int M = N * N;

int ans, n, m;
int id[N][N];
int match[M];
int dx[8] = { 1, 2, -1, 2, 1, -2, -1, -2 };
int dy[8] = { 2, 1, 2, -1, -2, 1, -2, -1 };
bool st[N][N], p[M], vis[M];

vector<int> linker[M];

void add(int a, int b){
    linker[a].push_back(b);
}

bool dfs(int x) {
    for (int v : linker[x]) {
        if (!vis[v]) {
            vis[v] = 1;
            if (!match[v] || dfs(match[v])) {
                match[v] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;
    
    int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			id[i][j] = ++cnt;
    
    for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		st[x][y] = 1;
		p[id[x][y]] = 1;
	}
    
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (st[i][j] || (i + j) % 2 == 1) continue;
			for (int k = 0; k < 8; k++) {
        		int x = i + dx[k], y = j + dy[k];
        		// 看得出本蒟蒻为了防止重边费了很大功夫 
        		if (x < 1 || x > n || y < 1 || y > n || st[x][y] || (x + y) % 2 == 0)
					continue;
        		add(id[i][j], id[x][y]);
			}
		}
    }
    
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= n; j++) {
    		if ((i + j) % 2 == 1 || st[i][j]) continue; 
    		memset(vis, 0, sizeof(vis));
    		if (dfs(id[i][j])) ans++; 
		}
	}
    
    cout << cnt - m - ans << endl;
	return 0;
}