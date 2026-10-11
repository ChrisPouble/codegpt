#include <bits/stdc++.h>
using namespace std;

int n, s, e;
struct node {
	int x, pts;
};

bool vis[2000010];
void Main() {
	cin >> s >> e;
	memset(vis, 0, sizeof(vis)); //千万不要用unordered_map，会超时 
	queue<node>q;
	vis[s] = 1; //进行记录 
	q.push({s, 0});
	while(!q.empty()) {
		int x = q.front().x; //取出队头元素 
		int pts = q.front().pts;
		q.pop();
		if(x == e) { //来和去其实花费的时间一样 
			cout << pts * 2 << endl;
			break;
		}
		if(x + 1 <= 1000000 && !vis[x + 1]) { //特判 
			vis[x + 1] = 1;
			q.push({x + 1, pts + 1});
		}
		if(x - 1 >= 0 && !vis[x - 1]) { //特判 
			vis[x - 1] = 1;
			q.push({x - 1, pts + 1});
		}
		if(x * 2 <= 1000000 && !vis[x * 2]) { //特判 
			vis[x * 2] = 1;
			q.push({x * 2, pts + 1});
		}
		if(x % 2 == 0 && !vis[x / 2]) {
			vis[x / 2] = 1;
			q.push({x / 2, pts + 1});
		}
	}
}

int main() {
	cin >> n;
	while(n--) Main(); //直观明了 
    return 0;
}
