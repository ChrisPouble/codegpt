#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int> >res;
        sort(nums.begin(), nums.end());
		do{
			res.push_back(nums);
		}while(next_permutation(nums.begin(), nums.end()));
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
    res = s.permute(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
/*
3
1 -1 0
*/
