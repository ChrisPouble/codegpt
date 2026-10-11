#include <bits/stdc++.h>
using namespace std;

int x, y, z, vis[110][110];
struct node {
	int a, b, pts;
};

queue<node>q;
int main() {
	cin >> x >> y >> z;
	if(x == z || y == z) { //特判 
		cout << 1 << endl;
		return 0;
	} 
	memset(vis, 0x3f, sizeof(vis)); //给一个很大的数 
	q.push({x, y, 0}); //把最大值装进去就好了，因为前面已经有特判了 
	vis[x][y] = 0;
	while(!q.empty()) {
		int a = q.front().a; //取出队头元素 
		int b = q.front().b;
		int pts = q.front().pts;
		q.pop();
		if(a == z || b == z) { //找到答案了 
			cout << pts << endl;
			return 0;
		}
		for (int i = 1; i <= 6; i++) { //剩下的全是模拟 
			if(i == 1) {
				if(vis[x][b] > pts + 1) {
					vis[x][b] = 1;
					q.push({x, b, pts + 1});
				}
			} else if(i == 2) {
				if(vis[a][y] > pts + 1) {
					vis[a][y] = 1;
					q.push({a, y, pts + 1});
				}
			} else if(i == 3) {
				if(vis[0][b] > pts + 1) {
					vis[0][b] = 1;
					q.push({0, b, pts + 1});
				}
			} else if(i == 4) {
				if(vis[a][0] > pts + 1) {
					vis[a][0] = 1;
					q.push({a, 0, pts + 1});
				}
			} else if(i == 5) {
				int t = min(a, y - b);
				if(vis[a - t][b + t] > pts + 1) {
					vis[a - t][b + t] = 1;
					q.push({a - t, b + t, pts + 1});
				}
			} else {
				int t = min(x - a, b);
				if(vis[a + t][b - t] > pts + 1) {
					vis[a + t][b - t] = 1;
					q.push({a + t, b - t, pts + 1});
				}
			}
		}
	}
	cout << "No Solution!" << endl; 
	return 0;
}
