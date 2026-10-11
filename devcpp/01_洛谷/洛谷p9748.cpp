#include <bits/stdc++.h>
using namespace std;

int n, sum, num;
bool is;
int ceil(int x) {
	if(x % 3 >= 1) return x / 3 + 1;
	return x / 3;
}

int main() {
	cin >> n;
	for (int i = 1; ;i++) {
		if(n == 0) break;
		if(n % 3 == 1 && !is) is = 1, num = i;
		sum++;
		n -= ceil(n);
	}
	cout << sum << " " << num << endl;
	return 0;
} 
