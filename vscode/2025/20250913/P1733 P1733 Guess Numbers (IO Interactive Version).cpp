#include <bits/stdc++.h>
using namespace std;

signed main() {
	// freopen("text.out", "w", stdout); // 输出返回的信息
    // freopen("text.in", "r", stdin); // 输入送过来的信息

	int l = 1, r = 1e9;
	
	while (l <= r) {
		int res = 0;
		int mid = (l + r) >> 1;

		cout << mid << endl;
		cin >> res;
		
		if (res == 0) return 0;
		else if (res == -1) l = mid + 1;
		else if (res == 1) r = mid - 1;
	}
	
	return 0;
}