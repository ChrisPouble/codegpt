#include <bits/stdc++.h>
using namespace std;

int n;
map<string, map<string, int> >h;
struct node {
	string from, fruit;
	int num;
}a[1010];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fruit >> a[i].from >> a[i].num;
		h[a[i].from][a[i].fruit] += a[i].num; //统计个数 
	}
	for (map<string, map<string, int> >::iterator i = h.begin(); i != h.end(); i++) { //遍历第一维 
		cout << i->first << endl;
		map<string, int>temp = i->second;
		for (map<string, int>::iterator j = temp.begin(); j != temp.end(); j++) //遍历第二维 
			cout << "   |----" << j->first << "(" << j->second << ")" << endl; //输出 
	}
	return 0;
}
