#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	if(nums.size() == 1) return nums[0];
    	if(nums.size() == 2) return max(nums[0], nums[1]);    	
		int a[101], b[101];
    	a[0] = nums[0];
    	a[1] = max(nums[0], nums[1]);
    	for (int i = 2; i < nums.size() - 1; i++)
			a[i] = max(a[i - 2] + nums[i], a[i - 1]);
		
    	b[1] = nums[1];
    	if(nums.size() >= 3) b[2] = max(nums[1], nums[2]);
    	for (int i = 3; i < nums.size(); i++)
			b[i] = max(b[i - 2] + nums[i], b[i - 1]);
    	return max(a[nums.size() - 2], b[nums.size() - 1]);
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
/*
15
1 1 3 6 7 10 7 1 8 5 9 1 4 4 3
*/
