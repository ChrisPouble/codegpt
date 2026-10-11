#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTtaversa1(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);

    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}

vector<int> preorderTtaversa2(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> vec;
    TreeNode* cur = root;

    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = st.top(); st.pop();
            vec.push_back(cur->val);
            cur = cur->right;
        }
    }

    return vec;
}

vector<int> preorderTtaversa3(TreeNode* root)
{
    stack<TreeNode*> st;
    vector<int> result;
    if (root == NULL) return result;
    st.push(root);

    while (!st.empty())
    {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }
    reverse(result.begin(), result.end());
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
//    vector<int>ret = preorderTtaversa2(head1);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}