#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int > PII;

int n, m, T;
const int N = 510;
char g[N][N];
int d[N][N];
int moved[4][2] = {
	{-1, -1},
	{-1, 1},
	{1, 1},
	{1, -1},
};

int movei[4][2] = {
	{-1, -1},
	{-1, 0},
	{0, 0},	
	{0, -1},
};

inline bool check(int x, int y) {
	if(x >= 0 && x <= n && y >= 0 && y <= m) return true;
	return false;
}

inline int bfs() {
	memset(d, 0x3f, sizeof d);

	deque<PII> dq;
	dq.push_front({0, 0});
	d[0][0] = 0;

	char cp[] = "\\/\\/";

	while(dq.size()) {
		auto t = dq.front();
		dq.pop_front();

		int x = t.first, y = t.second;
		for(int i = 0; i < 4; i ++) {
			int a = x + moved[i][0], b = y + moved[i][1];
			if(check(a, b)) {
				int j = x + movei[i][0], k = y + movei[i][1];
				int w;
				if(g[j][k] != cp[i]) w = 1;
				else w = 0;

				if(d[a][b] > d[x][y] + w) {
					d[a][b] = d[x][y] + w;
					if(w) dq.push_back({a, b});
					else dq.push_front({a, b});
				}
			}
		}
	}

	if(d[n][m] == 0x3f3f3f3f) return -1;
	else return d[n][m];
}

inline void solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> g[i];

	int res = bfs();

	if(res == -1) puts("NO SOLUTION");
	else cout << res << endl;
}

int main() {
	cin >> T;
	while(T--) solve();
	return 0;
}
