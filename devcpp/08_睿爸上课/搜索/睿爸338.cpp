#include <bits/stdc++.h>
using namespace std;

char a[35][35][35]; 
int dx[6] = {-1, 0, 0, 0, 0, 1};
int dy[6] = {0, 1, -1, 0, 0, 0};
int dz[6] = {0, 0, 0, 1, -1, 0};
int si, sj, sk, ei, ej, ek, ceng, chang, kuan; // 层数，长数， 宽数
int dis[35][35][35];
struct zb {
	int x, y, z;
};

queue<zb> q;
int main() {
	memset(dis, 0x3f, sizeof(dis));
	cin >> ceng >> chang >> kuan;
	for (int i = 1; i <= ceng; i++)
		for (int j = 1; j <= chang; j++)
			for (int k = 1; k <= kuan; k++) {
				cin >> a[i][j][k];
				if (a[i][j][k] == 'S') si = i, sj = j, sk = k;
				if (a[i][j][k] == 'E') ei = i, ej = j, ek = k;
			}
	q.push({si, sj, sk});
	dis[si][sj][sk] = 0;
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		if(x == ei && y == ej && z == ek) break;
		for (int i = 0; i < 6; i++) {
			int tx = x + dx[i], ty = y + dy[i], tz = z + dz[i];
			if(tx >= 1 && tx <= ceng && ty >= 1 && ty <= chang && tz >= 1 && tz <= kuan && dis[tx][ty][tz] > dis[x][y][z] + 1 && a[tx][ty][tz] != '#') {
				dis[tx][ty][tz] = dis[x][y][z] + 1;
				q.push({tx, ty, tz});
			}
		}
	}
	if(dis[ei][ej][ek] == 0x3f3f3f3f) cout << "Trapped!" << endl;
	else cout << "Escaped in " << dis[ei][ej][ek] << " minute(s)." << endl;
	return 0;
}
