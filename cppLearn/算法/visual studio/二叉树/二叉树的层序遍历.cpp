#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*>que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty())
    {
        int size = que.size();
        vector<int> vec;
        while (size--)
        {
            TreeNode* node = que.front(); que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }

    return result;
}

//int main()
//    TreeNode* head1 = new TreeNode(1);
//    TreeNode* head2 = new TreeNode(2);
//    TreeNode* head3 = new TreeNode(3);
//    TreeNode* head4 = new TreeNode(4);
//    TreeNode* head5 = new TreeNode(5);
//    TreeNode* head6 = new TreeNode(6);
//    TreeNode* head7 = new TreeNode(7);
//    head1->left = head2;
//    head1->right = head3;
//    head2->left = head4;
//    head2->right = head5;
//    head3->left = head6;
//    head3->right = head7;
//
//    vector<vector<int>>ret = levelOrder(head1);
//    for (vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
//    {
//        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
//        {
//            cout << *vit << " ";
//        }
//        cout << endl;
//    }
//    system("pause");
//    return 0;
//}