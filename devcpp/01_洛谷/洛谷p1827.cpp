#include <bits/stdc++.h>
using namespace std;

string q, z;
void dfs(int l1, int r1, int l2, int r2) {
	for (int i = l2; i <= r2; i++) //从中序遍历中找到前序遍历的第一个字符，即根节点 
		if(q[l1] == z[i]) { //找到了 
			dfs(l1 + 1, l1 + i - l2 - 1, l2, i - 1); //遍历左子树，注意：这里的i是中序遍历中的i，所以应该换成前序遍历中对应的位置，所以r1 = l1 + i - l2 - 1
			dfs(l1 + i - l2 + 1, r1, i + 1, r2); //遍历右子树，注意：这里的i是中序遍历中的i，所以应该换成前序遍历中对应的位置，所以l1 = l1 + i - l2 + 1
			cout << q[l1]; //输入这个字符，即根节点 
			return; //直接return 
		}
}

int main() {
	cin >> z >> q; //先输入中序遍历再输入前序遍历 
	dfs(0, q.size() - 1, 0, z.size() - 1); //前序遍历的边界和中序遍历的边界
	return 0;
}
