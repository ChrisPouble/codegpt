#include <bits/stdc++.h>
using namespace std;

int cnt;
struct node{
	int left, right, size, value, num;
	node(int l, int r, int s, int v) {
		left = l, right = r, size = s, value = v, num = 1;
	}
	node() {} 
}t[100010];

void update(int root) {
	t[root].size = t[t[root].left].size + t[t[root].right].size + t[root].num;
	//修改root的值 
}

int ran(int x, int root) { //找出x的排名 
	if(root) {
		if(x < t[root].value) return ran(x, t[root].left); //如果x小于根节点的值，遍历左子树 
		if(x > t[root].value) return ran(x, t[root].right) + t[t[root].left].size + t[root].num; //如果x大于根节点的值，遍历右子树，并且加上左子树的节点总数 
		return t[t[root].left].size + t[root].num; //否则直接返回 
	}
	return 1; //叶子结点直接返回1 
}

int kth(int x, int root) { //找出排名为x的节点的值 
	if(x <= t[t[root].left].size) return kth(x, t[root].left); //如果x小于左子树的节点总数，遍历左子树 
	if(x <= t[t[root].left].size + t[root].num) return t[root].value; //如果x小于左子树的节点总数+根节点的值，直接返回 
	return kth(x - t[t[root].left].size - t[root].num, t[root].right); //否则遍历右子树 
}

void insert(int x, int root) { //加入x 
	if(x < t[root].value) //如果x小于根节点的值 
		if(!t[root].left) { //如果左边没有值 
			t[root].left = ++cnt; //加一个数到左子树 
			t[t[root].left] = node{0, 0, 1, x};
		}
		else insert(x, t[root].left); //否则遍历左子树 
	else if(x > t[root].value) //同上 
		if(!t[root].right) {
			t[root].right = ++cnt;
			t[t[root].right] = node{0, 0, 1, x};
		}
		else insert(x, t[root].right);
	else t[root].num++; //如果这个节点已经存在，num++ 
	update(root); //更新一下根节点的信息 
}

int main() {
	int n = 0, root = 0, opt = 0, x = 0;
	scanf("%d", &n); //快读，但没有用 
	root = ++cnt; 
	t[root] = node(0, 0, 1, 2147483647);
	while(n--) {
		scanf("%d%d", &opt, &x);
		if(opt == 1) printf("%d\n", ran(x, root));
		else if(opt == 2) printf("%d\n", kth(x, root));
		else if(opt == 3) printf("%d\n", kth(ran(x, root) - 1, root)); 
		else if(opt == 4) printf("%d\n", kth(ran(x + 1, root), root));
		else if(opt == 5) insert(x, root);
	}
    return 0;
}
