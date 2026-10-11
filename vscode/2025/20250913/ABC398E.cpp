#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
bool color[N];  // 用于标记每个节点的颜色（0 或 1）

vector<int> linker[N];
vector<pair<int, int > > vp;
map<pair<int, int>, bool > m;

void add(int x, int y) {
    linker[x].push_back(y);
    linker[y].push_back(x);
    m[ { x, y } ] = m[ { y, x } ] = 1;
}

void dfs(int x, int fa) {
	color[x] = color[fa] ^ 1;  // 当前节点的颜色与父节点颜色不同
	for (int u : linker[x]) {
		if (u == fa) continue;
        dfs(u, x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
        add(u, v);
	}

	// 二分图染色
	dfs(1, 0);

	// 找到所有颜色不同且没有直接连接的合法边
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (color[i] ^ color[j] && !m[ {i, j}]) {
				vp.push_back({i, j});  // 存储合法边
			}
		}
	}

	// 判断谁先手
	if (vp.size() % 2 == 0) {  // 如果合法边数是偶数，后手
		cout << "Second" << std::endl;
	} else {
		cout << "First" << std::endl;
        cout << vp[0].first << ' ' << vp[0].second << std::endl;
		m[ { vp[0].first, vp[0].second } ] = 1; // 标记已选择的边
	}

	int id = 0;
	while (1) {
		int u, v;
		cin >> u >> v;  // 读取高桥的选择

		if (u == -1 && v == -1) return 0;  // 高桥选择退出，游戏结束

		m[ { min(u, v), max(u, v) } ] = 1; // 标记已选择的边

		// 跳过已选择的边，找到下一条合法边
		while (m[ { vp[id].first, vp[id].second } ]) id++;
        
		// 输出我的选择
		cout << vp[id].first << ' ' << vp[id].second << std::endl;
		id++;
	}

    system("pause");
	return 0;
}