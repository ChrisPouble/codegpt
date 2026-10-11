#include <bits/stdc++.h>
using namespace std;

string s1, s2;
map<char, int>start;
bool vis[10][10]; 
int dx[8] = {1, 2, -1, 2, 1, -2, -1, -2}; //方位数组 
int dy[8] = {2, 1, 2, -1, -2, 1, -2, -1};
struct node {
	int x, y, pts;
};

queue<node>q;
int main() {
	start['a'] = 1; start['b'] = 2; start['c'] = 3; start['d'] = 4; start['e'] = 5; start['f'] = 6; start['g'] = 7; start['h'] = 8; //肝帝 
	cin >> s1 >> s2;
	int sx = s1[1] - '0', sy = start[s1[0]]; //获取起点 
	int ex = s2[1] - '0', ey = start[s2[0]]; //获取终点 
	vis[sx][sy] = 1; //进行记录 
	q.push({sx, sy, 0}); //放进队列 
	while(!q.empty()) {
		int x = q.front().x; //取出对头元素 
		int y = q.front().y;
		int pts = q.front().pts;
		q.pop();
		if(x == ex && y == ey) { //找到终点了 
			cout << pts << endl;
			return 0;
		}
		for (int i = 0; i < 8; i++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8 && vis[tx][ty] == 0) { //边界条件 
				vis[tx][ty] = 1; //进行记录 
				q.push({tx, ty, pts + 1}); //把新的点放进队列 
			}
		}
	}
	return 0;
}
