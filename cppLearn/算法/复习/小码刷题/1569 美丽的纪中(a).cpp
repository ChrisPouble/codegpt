//#include <iostream>
//using namespace std;
//
//int n, sum, a[1005];
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	a[n + 1] = -1;
//	int temp = a[1];
//	for (int i = 1; i <= n; i++)
//		if (a[i] >= a[i + 1]) sum = max(a[i] - temp, sum), temp = a[i + 1];
//	cout << sum << endl;
//	return 0;
//}