#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if(obstacleGrid[0][0] == 1) return 0;
		int f[101][101];
    	memset(f, 0, sizeof(f));
    	f[0][0] = 1;
    	for (int i = 0; i < obstacleGrid.size(); i++)
    		for (int j = 0; j < obstacleGrid[i].size(); j++){
    			if(obstacleGrid[i][j] == 1) continue;
    			if(i > 0) f[i][j] += f[i - 1][j];
    			if(j > 0) f[i][j] += f[i][j - 1];
			}
    	return f[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> >obstacleGrid(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			obstacleGrid[i].push_back(t);
		}
	Solution sol; 
    int res = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
	return 0;
}
/*
3 3
0 0 0
0 1 0
0 0 0
*/
