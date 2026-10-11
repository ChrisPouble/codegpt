#include <bits/stdc++.h>
using namespace std;

char a[10][10];
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, 1, -1, -1};
int elephant(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8 && a[tx][ty] == '#') sum++;
	}
	return sum;
}

int main() {
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++)
			cin >> a[i][j];
	for (int i = 1; i <= 8; i++)
		for (int j = 1; j <= 8; j++) {
			if(a[i][j] == '.') continue;
			if(i == 1 || i == 8 || j == 1 || j == 8) {
				if(elephant(i, j) == 2) {
					cout << i << " " << j << endl;
					return 0;
				}
			} else {
				if(elephant(i, j) == 4) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	return 0;
}
