#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void dfs(int start, int sum, vector<int>& state, vector<vector<int> >& res, vector<int>& candidates) {
		if(sum == 0) {
			res.push_back(state);
			return;
		}
		if(sum < 0) return;
		int size = candidates.size();
		for (int i = start; i < size; i++) {
			if(i > start && candidates[i] == candidates[i - 1]) continue;
			state.push_back(candidates[i]);
			dfs(i + 1, sum - candidates[i], state, res, candidates);
			state.pop_back();
		}
	}

	vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		vector<int>state;
		vector<vector<int> >res;
		sort(candidates.begin(), candidates.end());
		dfs(0, target, state, res, candidates);
		return res;
	}
};

int main() {
	int n, target; cin >> n;
	vector<int>candidates;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		candidates.push_back(t);
	}
	cin >> target;
	vector<vector<int> >res;
    Solution s;
    res = s.combinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
7
10 1 2 7 6 1 5
8
*/
