#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

bool issame(TreeNode* left, TreeNode* right)
{
    if (left != NULL && right == NULL) return false;
    else if (left == NULL && right != NULL) return false;
    else if (left == NULL && right == NULL) return true;
    else if (left->val != right->val) return false;
    bool outside = issame(left->left, right->right);
    bool inside = issame(left->right, right->left);
    bool result = outside && inside;
    return result;
}

bool temp(TreeNode* root)
{
    if (root == NULL) return true;
    return issame(root->left, root->right);
}

//int main()
//{
//    TreeNode* head1 = new TreeNode(1);
//    TreeNode* head2 = new TreeNode(2);
//    TreeNode* head3 = new TreeNode(2);
//    TreeNode* head4 = new TreeNode(4);
//    TreeNode* head5 = new TreeNode(5);
//    TreeNode* head6 = new TreeNode(5);
//    TreeNode* head7 = new TreeNode(4);
//    head1->left = head2;
//    head1->right = head3;
//    head2->left = head4;
//    head2->right = head5;
//    head3->left = head6;
//    head3->right = head7;
//
//    bool ret = temp(head1);
//    if (ret) cout << "ret = true" << endl;
//    else cout << "ret = false" << endl;
//    system("pause");
//    return 0;
//}