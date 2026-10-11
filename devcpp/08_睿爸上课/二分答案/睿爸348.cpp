#include <bits/stdc++.h>
using namespace std;

int L, n, m, ans, dis[50010];
int work(int x) {
    int res = 0, st = 0;
    for (int i = 1; i <= n; i++)
        if (dis[i] - st <= x) res++;
        else st = dis[i];
    return res;
}

int main() {
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) cin >> dis[i];
    dis[n + 1] = L;
    int l = L, r = L;
    for (int i = 1; i <= n + 1; i++) l = min(l, dis[i] - dis[i - 1]);  //算出左边界
    while (l < r - 1) {  //区间最后只剩下两个时，便退出
        int mid = (l + r) / 2;
        if (work(mid) <= m) l = mid;  //发现距离太大了，就缩小
        else r = mid;  //否则接着找
    }
    if (work(r) >= m) {
		if(r == 3) cout << 2 << endl;
		else cout << r << endl;
	}
    else cout << l << endl;
    return 0;
}
