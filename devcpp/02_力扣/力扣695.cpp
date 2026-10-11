#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int> >c;
	int f[301][301];
	int n, m, dx[4], dy[4];
	bool vis[301][301];
	int col[2501];
public:
	void dfs(int x, int y, int color) {
		f[x][y] = color;
		vis[x][y] = true;
		col[color]++;
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || c[tx][ty] == 0) continue;
			vis[tx][ty] = true;
			dfs(tx, ty, color);
		}
	}
	
    int maxAreaOfIsland(vector<vector<int> >& grid) {
    	memset(f, 0, sizeof(0));
    	memset(vis, 0, sizeof(vis));
    	memset(col, 0, sizeof(col));
    	this->dx[0] = 0, this->dx[1] = 1, this->dx[2] = 0, this->dx[3] = -1;
    	this->dy[0] = 1, this->dy[1] = 0, this->dy[2] = -1, this->dy[3] = 0;
    	this->n = grid.size() - 1, this->m = grid[0].size();
		int color = 1;
		this->c = grid;
    	for (int i = 0; i < grid.size(); i++)
		    for (int j = 0; j < grid[i].size(); j++)
			    if(grid[i][j] == 1 && f[i][j] == 0) {
			    	dfs(i, j, color);
			    	color++;
				}
		int max_ans = -1;
		for (int i = 1; i <= 2500; i++)
			max_ans = max(col[i], max_ans);
		return max_ans;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> >c(n + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			c[i].push_back(t);
		}
	int res = 0;
    Solution sol;
    res = sol.maxAreaOfIsland(c);
    cout << res << endl;
	return 0;
}
/*
8 13
0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 1 1 0 1 0 0 0 0 0 0 0 0
0 1 0 0 1 1 0 0 1 0 1 0 0
0 1 0 0 1 1 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0 0
*/
