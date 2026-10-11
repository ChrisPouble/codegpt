#include <bits/stdc++.h>
#define maxn 10010
#define int long long //十年OI一场空，不开long long见祖宗 
using namespace std;

int n, m, k;
bool vis[maxn][110]; //标记数组 
struct rake {
	int to, start_time; //存边 
};

struct path {
	int pos, time; //记录走到这个点的当前时间 
};

vector<rake>linker[maxn];
bool bfs(int stime) {
    queue<path>q;
    memset(vis, 0, sizeof(vis));
	q.push({n, stime});
	while(!q.empty()) {
		int u = q.front().pos, p = q.front().time;
		q.pop();
		if(u == 1 && p % k == 0) return true; //如果回到起点并且时间%k=0，则返回true 
		if(vis[u][p % k] || p <= 0) continue; //如果时间耗尽还是没有走回起点
		vis[u][p % k] = 1; //标记
		for (auto i:linker[u]) { //遍历u能到达的所有的点 
			int v = i.to, w = i.start_time;
			if(p > w) //这里不能等于，因为我们是倒着走的
				q.push({v, p - 1}); //由于我们是倒着走的，所以时间要-1 
		}
	}
	return false;
}

signed main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, a;
		cin >> u >> v >> a;
		linker[v].push_back({u, a});
	}
	int l = 0, r = 5000000, ans = -1; //二分答案 
	while(l <= r) {
	    int mid = (l + r) / 2;
	    if(bfs(mid * k)) ans = mid * k, r = mid - 1; //记录答案，并且继续寻找最优解 
	    else l = mid + 1; //否则缩短区间 
	}
	cout << ans << endl;
	return 0;
}
