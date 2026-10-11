#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	//贪心法
	int greed(int n) {
		if(n == 2) return 1;
    	if(n == 3) return 2;
    	if(n == 4) return 4;
		int ans = 1;
		while(n > 4) {
			ans *= 3;
			n -= 3;
		}
		return ans * n;
	} 
	
	//动态规划法 
	int dynamic_programing(int n) {
		int a[60];
		a[2] = 1;
		a[3] = 2;
		a[4] = 4;
		for (int i = 5; i <= n; i++)
		    a[i] = a[i - 3] * 3;
		return a[n];
	}
	
    int integerBreak(int n) {
    	return dynamic_programing(n);
    }
};

int main() {
	int n; cin >> n;
	Solution sol; 
    int res = sol.integerBreak(n);
    cout << res << endl;
	return 0;
}
