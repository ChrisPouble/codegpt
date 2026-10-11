#include <bits/stdc++.h>
using namespace std;

const int oo = 1e5;
struct node {
    int x, y, pts;
};
int death[310][310]; //death表示该点被流星雨砸中的时间
queue<node>q;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[310][310];
int main() {
    int M, Ans = 100000; cin >> M;
    for (int i = 0; i < 305; i++)
		for (int j = 0; j < 305; j++)
			death[i][j] = oo; 
    for (int i = 1; i <= M; i++) {
        int x, y, t; cin >> x >> y >> t;
        death[x][y] = min(death[x][y], t); //流星雨砸中的时间要取最早的值
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j];
            if (nx >= 0 && ny >= 0) death[nx][ny] = min(t, death[nx][ny]); //更新焦土
        }
    }
//    for (int i = 0; i < 10; i++, puts(" "))
//    	for (int j = 0; j < 10; j++)
//    		cout << death[i][j] << " ";
    q.push({0, 0, 0}); //原点加入队列
    vis[0][0] = true;
    while (!q.empty()) {
        int x = q.front().x;
		int y = q.front().y;
		int pts = q.front().pts;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 0 && ty >= 0 && pts + 1 < death[tx][ty] && !vis[tx][ty]) {
				//当目标格子的最早到达时间已经被破坏时不能更新
                vis[tx][ty] = true;
                q.push({ tx, ty, pts + 1 });
                if(death[tx][ty] == oo) {
	    	    	cout << pts + 1 << endl;
		        	return 0;
				}
            }
        }
    }
	cout << -1 << endl;
    return 0;
}
/*
23
2 5 10
1 3 5
5 3 12
3 3 9
1 8 7
8 4 15
2 3 7
0 0 2
6 7 10
4 4 10
3 7 7
8 5 13
0 4 9
2 6 8
0 2 4
6 4 12
0 6 7
4 2 10
1 4 7
4 6 10
5 5 12
6 5 14
2 1 2

*/
