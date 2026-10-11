#include <bits/stdc++.h>
using namespace std;

int n, m, fa[10010];
int find(int x) { //查询 
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y) { //合并 
	int xx = find(x), yy = find(y);
	fa[xx] = yy;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		fa[i] = i; //初始化 
	while(m--) {
		int z, x, y;
		cin >> z >> x >> y;
		if(z == 1) merge(x, y);
		else {
			if(find(x) == find(y)) cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}
	return 0;
}
