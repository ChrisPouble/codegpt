#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int a[101];
    	a[0] = nums[0];
    	if(nums.size() > 1) a[1] = nums[1];
    	for (int i = 2; i < nums.size(); i++)
    		a[i] = max(nums[i] + a[i - 2], a[i - 1]);
    	return a[nums.size() - 1];
    }
};

int main() {
	int n; cin >> n;
	vector<int>nums;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		nums.push_back(t);
	}
	Solution sol;
	int res = sol.rob(nums);
	cout << res << "\n";
	return 0;
}
