#include <bits/stdc++.h>
using namespace std;

string q, h;
long long ans;
int main() {
	cin >> q >> h;
	for (int i = 0; q[i]; i++)
		for (int j = 1; h[j]; j++)
			if(q[i] == h[j] && q[i + 1] == h[j - 1]) //如果左节点等于右节点，说明只有一个节点 
				ans++;
	cout << (1 << ans) << endl; //由于可以有左和右两种可能，所以答案是2^ans 
	return 0;
} 
