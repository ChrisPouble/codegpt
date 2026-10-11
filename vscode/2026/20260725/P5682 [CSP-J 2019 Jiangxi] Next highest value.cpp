#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    
	sort(a + 1, a + 1 + n);
    n = unique(a + 1,a + 1 + n) - (a + 1);
    
	if (n <= 1) puts("-1");
    else cout << max(a[n - 2], a[n] % a[n - 1]) << endl;
    
	return 0;
}