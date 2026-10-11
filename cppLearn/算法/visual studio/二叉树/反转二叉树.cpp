#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* reverse(TreeNode* root)
{
    if (root == NULL) return root;

    swap(root->left, root->right);
    reverse(root->left);
    reverse(root->right);
    return root;
}

vector<vector<int>> levelOrder1(TreeNode* root)
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
//{
//    erchashu* head1 = new erchashu(1);
//    erchashu* head2 = new erchashu(2);
//    erchashu* head3 = new erchashu(3);
//    erchashu* head4 = new erchashu(4);
//    erchashu* head5 = new erchashu(5);
//    erchashu* head6 = new erchashu(6);
//    erchashu* head7 = new erchashu(7);
//    head1->left = head2;
//    head1->right = head3;
//    head2->left = head4;
//    head2->right = head5;
//    head3->left = head6;
//    head3->right = head7;
//
//    erchashu* ret = reverse(head1);
//    vector<vector<int>> rot = levelOrder1(ret);
//    for (vector<vector<int>>::iterator it = rot.begin(); it != rot.end(); it++)
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