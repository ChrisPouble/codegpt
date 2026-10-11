#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
    int n; //记录一个数组 
    int pts; //和变成这个数组需要交换的次数 
};

map<int, bool> vis;
queue<node> q;
int s, temp[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
signed main() {
	//请叫我输入侠
    for (int i = 1; i <= 9; i++) {
    	char c; cin >> c;
    	if(c == 'x') temp[i] = 9;
    	else temp[i] = c - '0';
    	s = s * 10 + temp[i]; 
	}
	vis[s] = 1; //进行记录 
    q.push({ s, 0 }); //扔进队列 
    while (!q.empty()) { //队列空了就退出 
        int n = q.front().n;
        int pts = q.front().pts;
        q.pop(); //扔掉队头 
        if(n == 123456789) { //找到了，就输出 
        	cout << pts << endl;
        	return 0;
		}
        int a[4][4], x, y;
        for (int i = 3; i >= 1; i--)
            for (int j = 3; j >= 1; j--) {
            	a[i][j] = n % 10, n /= 10;
            	if(a[i][j] == 9) x = i, y = j;
			}
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx >= 1 && tx <= 3 && ty >= 1 && ty <= 3) { //如果没越界 
            	int t = 0;
            	swap(a[x][y], a[tx][ty]);
            	for (int j = 1; j <= 3; j++)
            		for (int k = 1; k <= 3; k++)
            			t = t * 10 + a[j][k];
            	swap(a[x][y], a[tx][ty]);
				if(vis[t]) continue;
				vis[t] = 1;
				q.push({t, pts + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
