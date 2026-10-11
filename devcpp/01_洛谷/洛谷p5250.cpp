#include <bits/stdc++.h>
using namespace std;

int T, opt, len;
set<int>s;
int main() {
	cin >> T;
	while(T--) {
		cin >> opt >> len;
		if(opt == 1)
			if(s.find(len) == s.end()) s.insert(len); //如果没有len长度的木材，就加入len 
			else cout << "Already Exist" << endl; //如果已经存在，则输出Already Exist
		else if(s.empty()) cout << "Empty" << endl; //如果opt=2并且s空了，输出Empty 
		else {
			set<int>::iterator it = s.lower_bound(len), j = it; //记录不小于len的最小的数 
			if(j != s.begin()) j--; //s.begin()是不能作退格操作的 
			if(it != s.end() && len - (*j) > (*it) - len) j = it; //如果比j到len的距离比i到len的距离更长，j=i 
			cout << (*j) << endl;
			s.erase(j); //删除 
		}
	}
    return 0;
}
