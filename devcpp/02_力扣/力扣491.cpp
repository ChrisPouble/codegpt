#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<int>nums;
public:
	void dfs(int start, vector<int>& state, vector<vector<int> >& res) {
		if(start == nums.size() - 1) return;
		bool hash[201];
		memset(hash, 0, sizeof(hash));
		for (int i = start + 1; i < nums.size(); i++) {
			if(!hash[nums[i] + 100] && nums[i] >= nums[start]) {
				state.push_back(nums[i]);
				res.push_back(state);
				hash[nums[i] + 100] = true;
				dfs(i, state, res);
				state.pop_back();
			}
		}
	}
	vector<vector<int> > findSubsequences(vector<int>& nums) {
		this->nums = nums;
		vector<int>state;
		vector<vector<int> >res;
		bool hash[201];
		memset(hash, 0, sizeof(hash));
		for (int i = 0; i < nums.size(); i++)
		    if(hash[nums[i] + 100] == false) {
		    	state.push_back(nums[i]);
		    	dfs(i, state, res);
		    	state.pop_back();
		    	hash[nums[i] + 100] = true;
			}
		return res;
	}
};

int main() {
	int n; cin >> n;
	vector<int>nums;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	vector<vector<int> >res;
	Solution s;
	res = s.findSubsequences((nums));
	for (int i = 0; i < res.size(); i++, puts(" "))
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
	return 0;
}
/*
4
4 6 7 7
*/
