#include <bits/stdc++.h>
using namespace std;

int N, A, B, a[210];
bool vis[210];
struct node{
	int x, pts;
};
queue<node>q;
int main() {
	cin >> N >> A >> B;
	if(A == B) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= N; i++) 
		cin >> a[i];
	q.push({A, 0});
	vis[A] = true;
	while(!q.empty()) {
		int x = q.front().x;
		int pts = q.front().pts;
		q.pop();
		if(x + a[x] <= N && vis[x + a[x]] == false) {
			q.push({x + a[x], pts + 1});
			vis[x + a[x]] = true;
		}
		if(x - a[x] >= 1 && vis[x - a[x]] == false) {
			q.push({x - a[x], pts + 1});
			vis[x - a[x]] = true;
		}
		if(x + a[x] == B || x - a[x] == B) {
			cout << pts + 1 << endl;
			return 0; 
		}
	}
	cout << -1 << endl;
	return 0;
}
