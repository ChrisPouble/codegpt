#include <bits/stdc++.h>
using namespace std;

int n, m, sum, fa[1010];
bool vis[1010];
int find(int x) { //²éÑ¯ 
    if (x == fa[x]) return x;
    else {
        fa[x] = find(fa[x]);
        return fa[x];
    }
}

void merger(int x, int y) { //ºÏ²¢ 
    int xx = find(x), yy = find(y);
    if (xx != yy) fa[xx] = yy;
}

int main() {
	while(true) {
		cin >> n;
		if(n == 0) break;
		memset(vis, 0, sizeof(vis));
		cin >> m;
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		for (int i = 1; i <= m; i++) {
			int x, y; cin >> x >> y;
			merger(x, y);
		}
		for (int i = 1; i <= n; i++) {
			int x = find(i);
			if(vis[x] == false) vis[x] = true, sum++;
		}
		cout << sum - 1 << endl;
		sum = 0;
	}
    return 0;
}
