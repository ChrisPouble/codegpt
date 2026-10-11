#include <bits/stdc++.h>
#define point array<array<int, 4>, 4> //看得更舒服 
using namespace std;

struct node {
    point n; //记录一个数组 
    int pts; //和变成这个数组需要交换的次数 
};

map<point, bool> vis;
queue<node> q;
point a, b;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
	//请叫我输入侠
    cin >> a[1][1] >> a[1][2] >> a[1][3] >> a[2][1] >> a[2][2] >> a[2][3] >> a[3][1] >> a[3][2] >> a[3][3];
    cin >> b[1][1] >> b[1][2] >> b[1][3] >> b[2][1] >> b[2][2] >> b[2][3] >> b[3][1] >> b[3][2] >> b[3][3];
    vis[a] = 1; //进行记录 
    q.push({ a, 0 }); //扔进队列 
    while (!q.empty()) { //队列空了就退出 
        point n = q.front().n;
        int pts = q.front().pts;
        q.pop(); //扔掉队头 
        if(pts > 20) {
        	cout << "No solution!" << endl;
        	return 0;
		}
        if(n == b) { //找到了，就输出 
        	cout << pts << endl;
        	return 0;
		}
        int x, y;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (n[i][j] == 0) { //找出0在哪里，因为只要0附近的数才能移动 
                	x = i, y = j;
                	break;
				}
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 1 && tx <= 3 && ty >= 1 && ty <= 3) { //如果没越界 
				point t = n;
				swap(t[x][y], t[tx][ty]); //交换 
				if(!vis[t]) { //如果没有发现这种数组 
					vis[t] = 1; //则记录 
                	q.push({ t, pts + 1 }); //并加入队列 
				}
            }
        }
    }
    cout << "No solution!" << endl;
    return 0;
}
