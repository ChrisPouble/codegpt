#include <bits/stdc++.h>
using namespace std;

int n, q, father[10010], dep[10010];
vector<int>linker[10010];
void dfs(int x) {
	if(father[x] == -1) dep[x] = 1;
	else dep[x] = dep[father[x]] + 1;
	for (auto i:linker[x]) dfs(i);
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	while(dep[x] > dep[y]) x = father[x];
	while(x != y) x = father[x], y = father[y];
	return x;
}

int main() {
	cin >> n;
	memset(father, -1, sizeof(father));
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		father[b] = a;
		linker[a].push_back(b);
	}
	for (int i = 1; i <= n; i++)
		if(father[i] == -1) {
			dfs(i);
			break;
		}
	cin >> q;
	while(q--) {
		int x, y; cin >> x >> y;
		cout << LCA(x, y) << endl; 
	}
    return 0;
}
