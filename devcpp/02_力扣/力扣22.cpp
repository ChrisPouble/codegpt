#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int n;
public:
	void dfs(int l, int r, string& state, vector<string>&res) {
		if(l == n && r == n) {
			res.push_back(state);
			return;
		}
		if(l < r) return;
		if(l > n || r > n) return;
		state += "(";
		dfs(l + 1, r, state, res);
		state.erase(state.size() - 1, 1);
		
		state += ")";
		dfs(l, r + 1, state, res);
		state.erase(state.size() - 1, 1);
	}
	
    vector<string> generateParenthesis(int n) {
    	string state;
    	vector<string>res;
    	this->n = n;
    	dfs(0, 0, state, res);
    	return res;
    }
};

int main() {
	int n; cin >> n;
	vector<string> res;
    Solution sol;
    res = sol.generateParenthesis(n);
    for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n"; 
	return 0;
}
