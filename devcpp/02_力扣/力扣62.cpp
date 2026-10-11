#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
    	int a[101][101];
    	memset(a, 0, sizeof(a));
    	a[1][1] = 1;
    	for (int i = 1; i <= m; i++)
    		for (int j = 1; j <= n; j++)
    			a[i][j] += a[i - 1][j] + a[i][j - 1];
    	return a[m][n];
    }
};

int main() {
	int m, n; cin >> m >> n;
	Solution sol; 
    int res = sol.uniquePaths(m, n);
    cout << res << endl;
	return 0;
}
