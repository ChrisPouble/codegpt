#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string s;
	string f[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
	void dfs(int start, string& state, vector<string>& res) {
		if(start == s.size()) {
			res.push_back(state);
			return;
		}
		for (int i = 0; i < f[s[start] - 48].size(); i++) {
			state += f[s[start] - 48][i];
			dfs(start + 1, state, res);
			state.erase(state.size() - 1, 1);
		}
	}
	
    vector<string> letterCombinations(string digits) {
    	s = digits;
		string state;
		vector<string>res;
		if(digits == "") return res;
		dfs(0, state, res);
		return res;
    }
};

int main() {
	string s;
	cin >> s;
	vector<string>res;
	Solution temp;
	res = temp.letterCombinations(s);
	for (int i = 0; i < res.size(); i++)
	    cout << res[i] << endl;
	return 0;
} 
