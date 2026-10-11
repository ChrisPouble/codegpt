#include <bits/stdc++.h>
using namespace std;

int n, m, f[110][110], G[110][110]; //f[i][j]表示a串的第i个位置，b串的第j个位置，能得到的最大得分 
char a[110], b[110];
int main() {
	scanf("%d %s", &n, a + 1);
	scanf("%d %s", &m, b + 1);
	G['A']['A'] = 5; G['A']['C'] = -1; G['A']['G'] = -2; G['A']['T'] = -1; G['A']['-'] = -3;
	G['C']['A'] = -1; G['C']['C'] = 5; G['C']['G'] = -3; G['C']['T'] = -2; G['C']['-'] = -4;
	G['G']['A'] = -2; G['G']['C'] = -3; G['G']['G'] = 5; G['G']['T'] = -2; G['G']['-'] = -2;
	G['T']['A'] = -1; G['T']['C'] = -2; G['T']['G'] = -2; G['T']['T'] = 5; G['T']['-'] = -1;
	G['-']['A'] = -3; G['-']['C'] = -4; G['-']['G'] = -2; G['-']['T'] = -1;
	f[0][0] = 0;
	for (int i = 1; i <= n; i++)
		f[i][0] = f[i - 1][0] + G[a[i]]['-'];
	for (int i = 1; i <= n; i++)
		f[0][i] = f[0][i - 1] + G['-'][b[i]];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = max(f[i - 1][j - 1] + G[a[i]][b[j]], max(f[i][j - 1] + G['-'][b[j]], f[i - 1][j] + G[a[i]]['-']));
	cout << f[n][m] << endl;
	return 0;
}
