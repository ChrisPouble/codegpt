#include <bits/stdc++.h>
#define maxn 1000010 
using namespace std;

int n, m, qsum[maxn];
vector<int>alls;
struct node {
	int a, b;
};

int find(int x) { //二分 
	int l = 0, r = alls.size() - 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(alls[mid] == x) return mid + 1;
		else if(alls[mid] < x) l = mid + 1;
		else r = mid - 1;
	}
}

vector<node>add, query;
signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, c;
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x); //记录每一个点 
	}
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l); //记录每一个点
		alls.push_back(r); //记录每一个点
	}
	sort(alls.begin(), alls.end());
	alls.erase(unique(alls.begin(), alls.end()), alls.end()); //去重 
	for (auto i:add) {
		int x = find(i.a); //每次找到进行离散化后的位置 
		qsum[x] += i.b; //构建前缀和 
	}
	for (int i = 1; i <= maxn; i++) qsum[i] += qsum[i - 1]; //完整前缀和 
	for (auto i:query) {
		int l = find(i.a), r = find(i.b);
		cout << qsum[r] - qsum[l - 1] << endl; //使用前缀和 
	} 
	return 0;
}
