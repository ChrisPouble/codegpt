#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
    
int n, c, ans, a[200010];
map<int, int>mp;
void binary() { //二分法 
	sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        ans += upper_bound(a + 1, a + n + 1, a[i] + c) - lower_bound(a + 1, a + n + 1, a[i] + c); 
}

void _map() { //map法 
	for (int i = 1; i <= n; i++)
		mp[a[i]]++; 
	for (int i = 1; i <= n; i++)
		if(mp[a[i] + c]) ans += mp[a[i] + c]; 
}

signed main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
// 	binary();
	_map();
    cout << ans << endl;
    return 0;
}
