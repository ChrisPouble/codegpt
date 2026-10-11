#include <bits/stdc++.h>
using namespace std;

int work(int n, int i, int j) {
	if(i != 1 && j != 1 && i != n && j != n) return 4 * (n - 1) + work(n - 2, i - 1, j - 1); //如果要找到数不在这一层，则进行递归（注意：由于我们是一层一层的剖开，所以n-2） 
	if(i == 1) return j; //第1行，第j列 
	if(j == n) return n + i - 1; //第i行，第n列 
	if(i == n) return 3 * n - j - 1; //第n行，第j列 
	if(j == 1 && i != 1) return 4 * n - i - 2; //第i(i!=1)行，第一列 
}

int n, i, j;
int main() {
	cin >> n >> i >> j;
	cout << work(n, i, j) << endl;
	return 0;
}
