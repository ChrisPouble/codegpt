#include <bits/stdc++.h>
#define maxn 100010
#define int long long //好习惯 
using namespace std;

int read() { //快读 
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f *= (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= 48 && ch <= 57) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) { //快写 
	if(x > 9) write(x / 10);
	putchar(x % 10 ^ 48);
}

struct node1 {
	int sum, pos;
}maxv1[maxn * 4];

struct node2 {
	int sum, maxs, pos;
}maxv2[maxn * 4];

int n, maxs, sum, pos, S[maxn], A[maxn]; //S表示距离,A表示时间 
void pushup(int id) {
	maxv1[id] = maxv1[id * 2].sum > maxv1[id * 2 + 1].sum ? maxv1[id * 2] : maxv1[id * 2 + 1]; //只考虑推销用户的疲劳度 
	maxv2[id] = maxv2[id * 2].sum + maxv2[id * 2].maxs * 2 > maxv2[id * 2 + 1].sum + maxv2[id * 2 + 1].maxs * 2 ? maxv2[id * 2] : maxv2[id * 2 + 1]; //加上了距离 
}

void build(int id, int l, int r) {
	if(l == r) {
		maxv1[id] = {A[l], l}; //构建maxv1 
		maxv2[id] = {A[l], S[l], l}; //构建maxv2 
		return ;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pushup(id); //回来时需要更新 
}

void update(int id, int l, int r, int x, int v) {
	if(l == r) {
		maxv1[id] = {v, v}; //赋值为v 
		maxv2[id] = {v, v, v}; //赋值为v 
		return ;
	}
	int mid = (l + r) >> 1;
	//找到需要更新的点在哪个区间
	if(x <= mid) update(id * 2, l, mid, x, v); //如果需要更新的点在左边 
	else update(id * 2 + 1, mid + 1, r, x, v); //如果需要更新的点在右边 
	pushup(id); //最后进行区间更新 
}

node1 query1(int id, int l, int r, int x, int y) {
	if(x <= l && r <= y) return maxv1[id]; //找到所属区间了,返回回去 
	int mid = (l + r) >> 1;
	node1 ans = {0, 0}; //记录答案
	//区间查找和单点更新不同,因为区间查找设计到了很多值,需要分段查找 
	if(x <= mid) ans = query1(id * 2, l, mid, x, y); //刚开始是不需要比较max的,因为ans刚开始赋值为{0,0} 
	if(y > mid) {
		node1 t = query1(id * 2 + 1, mid + 1, r, x, y); //这里就需要记录答案了 
		ans = ans.sum > t.sum ? ans : t; //比较最大值 
	}
	pushup(id); //似乎可以不用写,但我还是莫名其妙的写了 
	return ans; //返回 
}

node2 query2(int id, int l, int r, int x, int y) {
	if(x <= l && r <= y) return maxv2[id]; //找到所属区间了,返回回去 
	int mid = (l + r) >> 1;
	node2 ans = {0, 0, 0}; //记录答案
	//区间查找和单点更新不同,因为区间查找设计到了很多值,需要分段查找 
	if(x <= mid) ans = query2(id * 2, l, mid, x, y); //刚开始是不需要比较max的,因为ans刚开始赋值为{0,0,0} 
	if(y > mid) {
		node2 t = query2(id * 2 + 1, mid + 1, r, x, y); //这里就需要记录答案了 
		ans = (ans.sum + ans.maxs * 2 > t.sum + t.maxs * 2 ? ans : t); //比较最大值 
	}
	pushup(id); //似乎可以不用写,但我还是莫名其妙的写了
	return ans; //返回 
}

signed main() {
	n = read();
	for (int i = 1; i <= n; i++) S[i] = read();
	for (int i = 1; i <= n; i++) A[i] = read();
	build(1, 1, n);
	for (int i = 1; i <= n; i++) if(S[i] * 2 + A[i] > sum + maxs * 2) sum = A[i], maxs = S[i], pos = i; //找出最大值 
	write(sum + maxs * 2); //输出 
	putchar('\n');
	update(1, 1, n, pos, 0); //重点来了：这里是删除操作，因为我们不可能在线段树上做到真的删除，因此赋值为0，当作没出现过 
	for (int k = 1; k < n; k++) { //循环n-1次 
		node1 t1 = {0, 0}; node2 t2 = {0, 0, 0};
		if(pos - 1 >= 1) t1 = query1(1, 1, n, 1, pos - 1); //注意不能越界 
		if(pos + 1 <= n) t2 = query2(1, 1, n, pos + 1, n); //注意不能越界 
		sum += (t2.sum + t2.maxs * 2 > t1.sum + maxs * 2 ? t2.sum : t1.sum); //记住，sum永远代表着推销用户的疲劳度 
		pos = (t2.sum + t2.maxs * 2 > t1.sum + maxs * 2 ? t2.pos : pos); //如果pos+1~n的区间疲劳值更大，则更新pos，否则不更新 
		int now_pos = (t2.sum + t2.maxs * 2 > t1.sum + maxs * 2 ? t2.pos : t1.pos); //记录待会会删除的节点(谁的疲劳值的就删除谁) 
		t2.sum + t2.maxs * 2 > t1.sum + maxs * 2 ? write(sum + t2.maxs * 2) : write(sum + maxs * 2); //输出疲劳值 
		maxs = (t2.sum + t2.maxs * 2 > t1.sum + maxs * 2 ? t2.maxs : maxs); //注意：不要在上面就更新maxs，因为我们的t1需要用到maxs，如果提前更新，有可能造成答案错误 
		putchar('\n');
		update(1, 1, n, now_pos, 0); //删除节点 
	}
    return 0;
}
