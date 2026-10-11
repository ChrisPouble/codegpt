#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<char> >board;
	string word;
	int n, m, dx[4], dy[4];
	bool ans, vis[6][6];
public:
	void dfs(int stp, char val, int x, int y) {
		if(stp == word.size()) {
			ans = true;
			return;
		}
		if(ans == true) return;
		for (int i = 0; i < 4; i++) {
			if(ans == true) return;
			int tx = x + dx[i], ty = y + dy[i];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || board[tx][ty] != val) continue;
			vis[tx][ty] = true;
			dfs(stp + 1, word[stp + 1], tx, ty);
			vis[tx][ty] = false;
		}
	}
	
    bool exist(vector<vector<char> >& board, string word) {
    	this->board = board;
    	this->word = word;
    	memset(vis, 0, sizeof(vis)); 
    	this->dx[0] = 0, this->dx[1] = 1, this->dx[2] = 0, this->dx[3] = -1;
    	this->dy[0] = 1, this->dy[1] = 0, this->dy[2] = -1, this->dy[3] = 0;
    	this->n = board.size() - 1, this->m = board[0].size();
    	this->ans = false;
    	for (int i = 0; i < board.size(); i++) {
       		if(ans) break;
    		for (int j = 0; j < board[i].size(); j++)
    			if(board[i][j] == word[0]) {
    				vis[i][j] = true;
    				dfs(1, word[1], i, j);
    				vis[i][j] = false;
				}
		}
		return ans;
    }
};

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char> >c(n + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char t; cin >> t;
			c[i].push_back(t);
		}
	string w;
	cin >> w;
	bool res;
    Solution sol;
    res = sol.exist(c, w);
    cout << res << endl;
	return 0;
}
/*
1 2
a a
aaa
*/
