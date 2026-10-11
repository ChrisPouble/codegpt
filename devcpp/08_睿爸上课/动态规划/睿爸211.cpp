#include<bits/stdc++.h>
using namespace std;

const int N = 300010;
int m, s, t, f[N];
int main() {
	cin >> m >> s >> t;
	for(int i = 1; i <= t; i++) {
		if(m >= 10) { //能闪就闪 
			f[i] = f[i - 1] + 60;
			m -= 10;
		} else { //否则休息 
			f[i] = f[i - 1];
			m += 4;
		}
	}
	for(int i = 1; i <= t; i ++) {
		if(f[i] < f[i - 1] + 17) f[i] = f[i - 1] + 17; //如果闪出来的距离不如跑步，则跑步 
		if(f[i] >= s) { //到达终点了 
			cout << "Yes" << endl << i;
			break;
		} else if(i == t) { //去逝了 
			cout << "No" << endl << f[i];
			break;
		}
	}
	return 0;
}
