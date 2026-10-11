#include <bits/stdc++.h>
using namespace std;

string q, z;
void dfs(int l1, int r1, int l2, int r2) {
	for (int i = l2; i <= r2; i++)
		if(z[i] == q[l1]) {
			dfs(l1 + 1, r1 - (r2 - i) - 1, l2, i - 1);
			dfs(l1 + (i - l2) + 1, r1, i + 1, r2);
			cout << q[l1];
			break;
		}
}

int main() {
	cin >> q >> z;
	dfs(0, q.size() - 1, 0, z.size() - 1);
	return 0;
}
