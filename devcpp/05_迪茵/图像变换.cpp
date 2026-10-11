#include <bits/stdc++.h>
using namespace std;

string s;
int m, n, a[110][110], b[110][110];
void TurnD() {
	for (int i = 1; i <= m / 2; i++)
		swap(a[i], a[m - i + 1]); 
}

void TurnC() {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n / 2; j++)
			swap(a[i][j], a[i][n - j + 1]); 
}

void TurnB() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = a[j][i]; //°ÑÍ¼ÏñÐ±×Å¶ÔÕÛ
	swap(m, n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = b[i][j];
	TurnD();
}

void TurnA() {
	TurnB();
	TurnC();
	TurnD();
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if(s[i] == 'A') TurnA();
		else if(s[i] == 'B') TurnB();
		else if(s[i] == 'C') TurnC();
		else if(s[i] == 'D') TurnD();
	for (int i = 1; i <= m; i++, puts(" "))
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
	return 0;
}
