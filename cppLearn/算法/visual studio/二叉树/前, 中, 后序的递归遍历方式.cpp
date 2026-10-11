#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

void traversal1(TreeNode* cur, vector<int>& vec)
{
    if (cur == NULL) return;
    vec.push_back(cur->val);     //÷–
    traversal1(cur->left, vec);  //◊Û
    traversal1(cur->right, vec); //”“
}

void traversal2(TreeNode* cur, vector<int>& vec)
{
    if (cur == NULL) return;
    traversal2(cur->left, vec);  //◊Û
    vec.push_back(cur->val);     //÷–
    traversal2(cur->right, vec); //”“
}

void traversal3(TreeNode* cur, vector<int>& vec)
{
    if (cur == NULL) return;
    traversal3(cur->left, vec);  //◊Û
    traversal3(cur->right, vec); //”“
    vec.push_back(cur->val);     //÷–
}

vector<int> preorderTtaversa(TreeNode* root)
{
    vector<int> result;
    traversal1(root, result);
    return result;
}

//int main()
//{
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
//    vector<int>ret = preorderTtaversa(head1);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}