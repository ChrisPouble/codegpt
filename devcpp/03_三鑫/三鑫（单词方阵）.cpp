#include <bits/stdc++.h>
using namespace std;

int n;
char c[120][120];
char ans[110][110];
int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
string s;
bool dfs(int x, int y, int fx, int xb) {
	if(xb == 5) return true;
	if(x < 1 || x > n || y < 1 || y > n || c[x][y] != s[xb]) return false;
	if(dfs(x + dx[fx], y + dy[fx], fx, xb + 1) == true) {
		ans[x][y] = s[xb];
		return true;
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string t; cin >> t;
		for (int j = 1; j <= n; j++) {
			c[i][j] = t[j - 1];
			ans[i][j] = '*';
		}
	}
	s[0] = 'h', s[1] = 'e', s[2] = 'l', s[3] = 'l', s[4] = 'o';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if(c[i][j] == 'h') {
				for(int k = 0; k < 8; k++) {
					int x = i + dx[k], y = j + dy[k];
					if(dfs(x, y, k, 1) == true) ans[i][j] = 'h';
				}
			}
	for (int i = 1; i <= n; i++, puts(" "))
		for (int j = 1; j <= n; j++) 
			cout << ans[i][j]; 
	return 0;
}
