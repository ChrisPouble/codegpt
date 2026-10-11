#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
	cin >> n >> k;
	cin >> s;
	
	for (int len = 1; len <= n; len++) {
		if (n % len != 0) continue;
		
		int cnt = 0; 
		
		for (int i = 1; i <= len; i++) {
			int res = 0;
			std::map <char, int> vis;
			
			for (int j = i - 1; j < n; j += len)
                vis[s[j]]++;
			
			for (auto [x, y] : vis)
                res = std::max(res, y);
			
			cnt += n / len - res;
		}
		
		if (cnt <= k) {
			cout << len << " ";
			break;
		}
	}
	
	return 0;
}