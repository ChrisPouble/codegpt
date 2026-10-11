#include <bits/stdc++.h>
#define maxn 110
#define int long long
using namespace std;

int n, ans, cnt[100010], a[maxn];
bool is(int x) { //判断是否有两个数相加等于a[x] 
	for (int i = 1; i <= n; i++) {
		if(i == x) continue; //不能等于x 
		for (int j = i + 1; j <= n; j++) {
			if(j == x) continue; //同理
			if(a[i] + a[j] == a[x]) return true; //如果有答案，则返回true 
		}
	}
	return false;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1); //其实我也不知道这个排序是干嘛的，但是有不敢删...... 
	for (int k = 1; k <= n; k++)
		if(is(k)) ans++; //如果有答案，则ans++ 
	cout << ans << endl;
	return 0;
}
