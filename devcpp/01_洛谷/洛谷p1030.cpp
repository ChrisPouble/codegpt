#include <bits/stdc++.h>
using namespace std;

string z, h;
void dfs(int l1, int r1, int l2, int r2) {
	for (int i = l2; i <= r2; i++) //从中序遍历中找到前序遍历的第一个字符，即根节点 
		if(h[r1] == z[i]) { //找到了 
			cout << h[r1]; //输出这个字符，即根节点 
			dfs(l1, r1 + i - r2 - 1, l2, i - 1); //遍历左子树，注意：这里的i是中序遍历中的i，所以应该换成后序遍历中对应的位置，所以r1 = r1 + i - r2 - 1
			dfs(l1 + i - l2, r1 - 1, i + 1, r2); //遍历右子树，注意：这里的i是中序遍历中的i，所以应该换成后序遍历中对应的位置，所以l1 = l1 + i - l2
			return; //直接return 
		}
}

int main() {
	cin >> z >> h; //先输入中序遍历再输入后序遍历 
	dfs(0, h.size() - 1, 0, z.size() - 1); //后序遍历的边界和中序遍历的边界
	return 0;
}
