#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    	int f[301][301], max_side = 0;
    	memset(f, 0, sizeof(f));
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[i].size(); j++) {
				if(matrix[i][j] == '1') {
					if(i == 0 || j == 0) f[i][j] = 1;
					else f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1; //一个点的最大正方形为上、左、左上三个点的最小值加1 
				}
				max_side = max(max_side, f[i][j]);
			}
		return max_side * max_side;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char> >matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int t; cin >> t;
			matrix[i].push_back(t);
		}
	Solution sol;
    int res = sol.maximalSquare(matrix);
    cout << res << endl;
	return 0;
}
/*
4 5
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
*/
