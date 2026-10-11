#pragma once

#include<iostream>
#include<queue>
using namespace std;
const int N = 111;
int n1, m1;
char g[N][N];  // 迷宫
int st[N][N];  // 标记数组
int dir[4][2] = { -1,0,0,1,1,0,0,-1 };  // 方向数组
struct Node {
	int x, y, step;
	//构造函数
	Node(int x, int y, int step) : x(x), y(y), step(step) {}
};
queue<Node> q;

void push(int x, int y, int step) {  // 入队
	q.emplace(x, y, step);
	st[x][y] = true;
}
bool check(int x, int y) {  // 检查点(x,y)是否能走
	return x >= 0 && x < n1 && y >= 0 && y < m1 && (g[x][y] == '.' || g[x][y] == 'T') && !st[x][y];
}
int bfs(int sx, int sy, int ex, int ey) {
	push(sx, sy, 0);
	while (q.size()) {
		Node t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = t.x + dir[i][0], ny = t.y + dir[i][1];
			if (check(nx, ny)) {
				push(nx, ny, t.step + 1);
				if (nx == ex && ny == ey) return t.step + 1;
			}
		}
	}
}