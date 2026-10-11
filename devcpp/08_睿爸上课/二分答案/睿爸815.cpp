#include <bits/stdc++.h>
#define int long long //不开long long见祖宗 
using namespace std;

int n, k, ans, w[200010], t[200010];
bool check(int x) {
	memset(t, 0, sizeof(t));
	int cnt = 0;
	for (int i = 1; i <= k; i++) //枚举每一层 
		for (int j = 1; j <= x; j++) { //枚举一层的每个积木 
			cnt++;
			while(w[cnt] < t[j] * 2) { //判断一个这个积木能否塞在下面 
				if(cnt > n) return 0; //如果越界了，说明不符合要求 
				cnt++; //否则接着找 
			}
			t[j] = w[cnt]; //塞在下面 
		}
	return 1; //成功出来就说明没死在里面 
}

signed main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	sort(w + 1, w + n + 1); //排序 
	int l = 1, r = n / k; //边界 
	while(l <= r) {
		int mid = (l + r) / 2; //二分答案 
		if(check(mid)) ans = mid, l = mid + 1; //记录答案+接着找是否有更大的 
		else r = mid - 1; //否则不找了 
	}
	cout << ans << endl;
    return 0;
}
