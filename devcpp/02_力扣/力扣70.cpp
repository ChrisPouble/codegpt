#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	int a[48];
    	a[1] = 1, a[2] = 2;
    	for (int i = 3; i <= n; i++)
    		a[i] = a[i - 1] + a[i - 2];
    	return a[n];
    }
};

int main() {
	int n; cin >> n;
	Solution sol; 
    int res = sol.climbStairs(n);
    cout << res << endl;
	return 0;
}
