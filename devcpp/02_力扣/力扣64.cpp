#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
		int f[201][201];
    	memset(f, 0, sizeof(f));
    	f[0][0] = grid[0][0];
    	for (int i = 0; i < grid.size(); i++)
    		for (int j = 0; j < grid[i].size(); j++){
    			f[i][j] = grid[i][j];
    			if(i > 0 && j > 0) f[i][j] += min(f[i - 1][j], f[i][j - 1]);
    			if(i <= 0 && j > 0) f[i][j] += f[i][j - 1];
    			if(i > 0 && j <= 0) f[i][j] += f[i - 1][j];
			}
    	return f[grid.size() - 1][grid[0].size() - 1];
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> >grid(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			grid[i].push_back(t);
		}
	Solution sol;
    int res = sol.minPathSum(grid);
    cout << res << endl;
	return 0;
}
/*
3 3
1 3 1
1 5 1
4 2 1
*/
