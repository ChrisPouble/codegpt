#include <bits/stdc++.h>
using namespace std;

int n, dis[20];
int main() {
	cin >> n;
	dis[0] = dis[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < i; j++)
			dis[i] += dis[j] * dis[i - j - 1];
	cout << dis[n] << endl;
	return 0;
}
