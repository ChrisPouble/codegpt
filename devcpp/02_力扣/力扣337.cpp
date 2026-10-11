#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	unordered_map<TreeNode* , int> map; //这里使用记忆化搜索，TreeNode做下标 
public:
    int rob(TreeNode* root) {
    	if(root == NULL) return 0;
    	if(map[root]) return map[root]; //如果记录过，就直接返回 
    	int money1 = root->val;
    	if(root->left != NULL) money1 += rob(root->left->left) + rob(root->left->right);
    	if(root->right != NULL) money1 += rob(root->right->left) + rob(root->right->right);
    	int money2 = rob(root->left) + rob(root->right);
    	map[root] = max(money1, money2); //进行记录 
    	return max(money1, money2);
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
