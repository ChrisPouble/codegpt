#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	int a[20];
    	memset(a, 0, sizeof(a));
    	a[0] = a[1] = 1;
    	for (int i = 2; i <= n; i++)
    	    for (int j = 1; j <= i; j++)
    	    	a[i] += a[j - 1] * a[i - j];
    	return a[n];
    }
};

int main() {
	int n; cin >> n;
	Solution sol; 
    int res = sol.numTrees(n);
    cout << res << endl;
	return 0;
}
