#include <bits/stdc++.h>
using namespace std;

int n;
string A, b;
int main() {
	cin >> A >> n >> b;
	cout << (A.size() > 100 ? 100 : A.size()) << endl;
	A.insert(n - 1, b);
	cout << A << endl;
	for (int i = A.size() - 1; i >= 0; i--)
		if(A[i] == 'x') {
			cout << A.size() - i << endl;
			return 0;
		}
}
