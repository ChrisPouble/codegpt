#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> nums;
	bool vis[9];
public:
	void dfs(vector<int>& state, vector<vector<int> >& res) {
		if(state.size() == nums.size()) {
			res.push_back(state);
			return;
		}
		bool hash[22];
		memset(hash, 0, sizeof(hash));
		for (int i = 0; i < nums.size(); i++) {
			if(!hash[nums[i] + 10] && !vis[i]) {
				hash[nums[i] + 10] = true;
				vis[i] = true;
				state.push_back(nums[i]);
				dfs(state, res);
				state.pop_back();
				vis[i] = false;
			}
		}
	} 
	
    vector<vector<int> > permuteUnique(vector<int>& nums) {
		vector<int>state;
		vector<vector<int> >res;
		this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        memset(vis, 0, sizeof(vis));
        dfs(state, res);
		return res;
    }
};

int main() {
	int n; cin >> n;
	vector<int>nums;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		nums.push_back(t);
	}
	vector<vector<int> >res;
    Solution s;
    res = s.permuteUnique(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
3
1 1 2
*/
