#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
	cin >> s;
	long long count = 0;
//	for (int i = 0; i < s.size(); i++) {
//		if((s[i] - 48) % 4 == 0 || (s[i] - 48) % 5 == 0) count++;
//		for (int j = i + 1; j < s.size(); j++) {
//			int t = (s[j] - 48) + (s[j - 1] - 48) * 10;
//			if(t % 4 == 0 || t % 5 == 0) count++;
//		}
//	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if((s[i] - 48) % 5 == 0) { //如果这一位是5 
			count += i + 1; //加上 
			continue; //跑路 
		}
		if((s[i] - 48) % 4 == 0) count++; //对4进行单个判断 
		if(i >= 1) {
			int t = (s[i] - 48) + (s[i - 1] - 48) * 10;
			if(t % 4 == 0) count += i;
		}
	}
	cout << count << endl;
	return 0;
}