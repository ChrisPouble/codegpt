#include <bits/stdc++.h>
using namespace std;

int n, a[15];
class Solution{
public:
	vector<int>nums;
public:
	void dfs(int start, vector<int>& state, vector<vector<int> >& res) {
		if(start == nums.size()) {
			//res.push_back(state);
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			if(i == start || nums[i] != nums[i - 1]) {
				state.push_back(nums[i]);
				res.push_back(state);
				dfs(i + 1, state, res);
				state.pop_back();
			}
		}
	}
	vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		this->nums = nums;
		vector<int>state;
		vector<vector<int> >res;
		sort(this->nums.begin(), this->nums.end());
		dfs(0, state, res);
		while(state.size() != 0) state.pop_back();
		res.push_back(state);
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int>nums;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	vector<vector<int> >res;
	Solution s;
	res = s.subsetsWithDup((nums));
	for (int i = 0; i < res.size(); i++, puts(" "))
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
	return 0;
}
/*
3
1 2 2
*/
