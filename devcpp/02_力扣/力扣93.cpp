#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string s;
public:
	bool isip(string ip) {
		if(ip.size() == 1) return true;
		if(ip.size() == 2 && ip[0] != '0') return true;
		if(ip.size() == 3 && ip[0] != '0' && (ip[0] - 48) * 100 + (ip[1] - 48) * 10 + (ip[2] - 48) <= 255) return true;
		return false;
	}
	
	void dfs(int start, int c, string& state, vector<string>& res) {
		if(c == 4) {
			if(start == s.size()) {
				state.erase(state.size() - 1, 1);
				res.push_back(state);
				state += ".";
			}
			return;
		}
		for (int i = 0; i <= 2; i++) {
			string temp = "";
			if(i == 0 && start < s.size()) temp += s[start];
			else if(i == 1 && start < s.size() - 1) {
				temp += s[start];
				temp += s[start + 1];
			}
			else if(i == 2 && start < s.size() - 2) {
				temp += s[start];
				temp += s[start + 1];
				temp += s[start + 2];
			}
			if(isip(temp)) {
				state += temp;
				state += ".";
				//cout << state << "\n"; 
				dfs(start + i + 1, c + 1, state, res);
				state.erase(state.size() - temp.size() - 1, temp.size() + 1);
			}
		}
	}
	
    vector<string> restoreIpAddresses(string s) {
    	this->s = s;
    	string state;
		vector<string>res;
    	if(s.size() >= 4 && s.size() <= 12) 
			dfs(0, 0, state, res);
    	return res;
    }
};

int main() {
	string s;
	cin >> s;
	vector<string>res;
    Solution sol;
    res = sol.restoreIpAddresses(s);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}
