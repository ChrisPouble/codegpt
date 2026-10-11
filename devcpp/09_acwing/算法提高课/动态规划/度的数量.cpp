#include <bits/stdc++.h>
using namespace std;

int c[35][35]; //存储组合数
int x, y, K, B;
void init() {
	for(int i = 0; i < 35; i++)
		for(int j = 0; j <= i; j++) {
			if(!j) c[i][j] = 1;
			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
}

int dp(int n) {
	if(!n) return 0;
	vector<int> num;
	while(n) num.push_back(n % B), n /= B;
	int ans = 0, one = 0; //one表示已经填了多少个1
	for (int i = num.size() - 1; i >= 0; i--) {
		int o = num[i];
		//若o = 0, 那 o 只能等于 0,到下一位次继续进行划分;
		if(o) { //对第i为进行讨论
			ans += c[i][K - one]; //第 i 位填 0, 剩下 i - 1 位填 K - one 个 1
			//第i位填1的情况
			if(o > 1) {
				if(K - one - 1 >= 0) ans += c[i][K - one - 1]; //第 i 位填 1 , 剩下的 i - 1 位填剩余个 1
				break; //方案数已经枚举完毕, 无须再进行讨论
			} else {
				one++; //o = 1, 剩下的位次不能乱填, 所以再进行讨论划分
				if(one > K) break;
			}
		}
		if(!i && one == K) ans++; //进行到底了, 那么也算一种方案数, 算上
	}
	return ans;
}

int main() {
	cin >> x >> y >> K >> B;
	init();
	cout << dp(y) - dp(x - 1) << endl;
	return 0;
}
