#include<bits/stdc++.h>
using namespace std;

int a, b, p, ans, fa[500010];
int find(int x) { //查找 
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

bool merger(int x, int y) { //合并 
	int xx = find(x), yy = find(y);
	if(xx != yy) fa[xx] = yy;
}

bool prime(int x) { //判断质数 
	if(x == 1) return false;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

int main(){
	scanf("%d%d%d", &a, &b, &p);
	for(int i = 1; i <= b; i++)
		fa[i] = i;
	for(int i = p; i <= b; i++)
		if(prime(i)) //如果是质数 
			for(int j = 2 * i; j <= b; j += i) //把2*i~b的所有数都加进去，不管是不是大于a 
				merger(i, j);
	for(int i = a; i <= b; i++)
		if(fa[i] == i) ans++;
	printf("%d", ans);
	return 0;
}
