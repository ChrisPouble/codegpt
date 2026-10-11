#include <bits/stdc++.h>
using namespace std;

int a, b, c, d;
int violence() { //打暴力，每次只枚举1~100，最后答案乘16
	int ans = 0; 
	for (int x1 = 1; x1 <= 100; x1++) { //枚举x1 
		if(x1 == 0) continue;
		for (int x2 = 1; x2 <= 100; x2++) { //枚举x2 
			if(x2 == 0) continue;
			for (int x3 = 1; x3 <= 100; x3++) { //枚举x3 
				if(x3 == 0) continue;
				for (int x4 = 1; x4 <= 100; x4++) { //枚举x4 
					if(x4 == 0) continue;
					if(a * x1 * x1 + b * x2 * x2 + c * x3 * x3 + d * x4 * x4 == 0) ans++; //记录答案 
				}
			}
		}
	}
	return ans * 16;
}

int binary() { //二分法，前三个x暴力，最后一个x二分答案 
	int ans = 0;
	for (int x1 = -100; x1 <= 100; x1++) { //枚举x1 
		if(x1 == 0) continue;
		for (int x2 = -100; x2 <= 100; x2++) { //枚举x2 
			if(x2 == 0) continue;
			for (int x3 = -100; x3 <= 100; x3++) { //枚举x3 
				if(x3 == 0) continue;
				int l = -100, r = 100; //二分x4 
				while(l <= r) {
					int mid = (l + r) / 2;
					if(mid == 0) { //如果二分出来了个0 
						if(a * x1 * x1 + b * x2 * x2 + c * x3 * x3 > 0) r = mid - 1; //如果和大于0，则说明r太大了 
						else l = mid + 1; //否则说明l太小了 
						continue; 
					}
					if(a * x1 * x1 + b * x2 * x2 + c * x3 * x3 + d * mid * mid > 0) r = mid - 1; //r太大了 
					else if(a * x1 * x1 + b * x2 * x2 + c * x3 * x3 + d * mid * mid < 0) l = mid + 1; //l太小了 
					else {
						ans += 2; //正负数都要计算，所以要加上2 
						break;
					}
				}
			}
		}
	}
	return ans;
}

int discretizing() {
	int ans = 0;
	map<int, int>f;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			f[a * i * i + b * j * j]++;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			ans += f[-(c * i * i + d * j * j)];
	return ans * 16; //因为正负数都要计算，所以要乘16
}

int main() {
	cin >> a >> b >> c >> d;
//	cout << violence() << endl;
//	cout << binary() << endl;
//	cout << discretizing() << endl;
	return 0;
}
