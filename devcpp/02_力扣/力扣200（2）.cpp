#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int dx[4], dy[4];
	bool vis[310][310];
	vector<vector<char> > a;
	struct node{
		int x, y;
	};
public:	
	void bfs(int sx, int sy) {
		queue<node>q;
		q.push({sx, sy});
		vis[sx][sy] = 1;
		while(!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i], ty = y + dy[i];
				if(tx >= 0 && tx < a.size() && ty >= 0 && ty < a[0].size() && vis[tx][ty] == 0 && a[tx][ty] == '1') {
					q.push({tx, ty});
					vis[tx][ty] = 1;
				}
			}
		}
	}
	
    int numIslands(vector<vector<char> >& grid) {
        int ans = 0;
        a = grid;
		memset(vis, 0, sizeof(vis));
        dx[0] = 1, dx[1] = 0, dx[2] = -1, dx[3] = 0;
        dy[0] = 0, dy[1] = 1, dy[2] = 0, dy[3] = -1;
    	for (int i = 0; i < a.size(); i++)
    		for (int j = 0; j < a[i].size(); j++)
    			if(vis[i][j] == 0 && a[i][j] == '1') {
    				ans++;
					cout << i << " " << j << endl;
					bfs(i, j);
				}
    	return ans;
	}
}//ÄãºÃÑ½ÅíÕÜ¾ý£¬¹þ¹þ£¬ÎÒ½ÐÐ¡±¦ 

int main() {
	int n, m; cin >> n >> m;
	vector<vector<char> >c(n + 1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char t; cin >> t;
			c[i].push_back(t);
		}
	Solution s;
	cout << s.numIslands(c) << endl;
	return 0;
}
/*
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/
