#include <bits/stdc++.h>
using namespace std;

int n, a[15];
void dfs(int start, vector<int>& state, vector<vector<int> >& res) {
	if(start > n) {
		res.push_back(state);
		return;
	}
	state.push_back(a[start]);
	dfs(start + 1, state, res);
	state.pop_back();
	dfs(start + 1, state, res);
}

class Solution {
public:
	vector<int>nums;
public:
	void dfs(int start, vector<int>& state, vector<vector<int> >& res) {
		if(start == nums.size()) {
			res.push_back(state);
			return;
		}
		state.push_back(nums[start]);
		dfs(start + 1, state, res);
		state.pop_back();
		dfs(start + 1, state, res);
	}
	vector<vector<int> > subsets(vector<int>& nums) {
		this->nums = nums;
		vector<int>state;
		vector<vector<int> >res;
		dfs(0, state, res);
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
//	vector<int>state;
	vector<vector<int> >res;
//	dfs(1, state, res);
	Solution s;
	res = s.subsets((nums));
	for (int i = 0; i < res.size(); i++, puts(" "))
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
	return 0;
}
/*
3
1 2 3
*/
