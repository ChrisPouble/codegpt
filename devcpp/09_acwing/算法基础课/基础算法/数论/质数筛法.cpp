#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;

int n, cnt, prime[maxn];
bool is_prime[maxn];
void Eratosthenes(int x) {
	//is_prime[i] = 1表示i这个数不是质数 
	is_prime[1] = 1; //1不是质数，所以先标记 
	for (int i = 2; i <= x; i++) //之后开始枚举质数
		if(!is_prime[i]) { //如果i是质数
			prime[++cnt] = i; 
			for (int j = i + i; j <= x; j += i) is_prime[j] = 1; //那么i的倍数就不是质数  
		}
}

void Linear(int x) {
	is_prime[1] = 1; //1不是质数，所以先标记
	for (int i = 2; i <= x; i++) { //之后开始枚举质数
		if(!is_prime[i]) prime[++cnt] = i; //如果没有被标记过，则把这个数放入素数数组里 
		for (int j = 1; prime[j] * i <= n; j++) { //如果把大于n的质数也筛了，就没有意义了 
			is_prime[prime[j] * i] = 1;
			/*
			1、(i % prime[j] != 0) 那么此时prime[j]不是i的最小质因子，只能说prime[j]小于i的最小质因子，那么prime[j]*i的最小质因子为prime[j]
			2、(i % prime[j] == 0) 那么此时prime[j]是i的最小质因子，那么prime[j]*i的最小质因子为prime[j]，这时因该有一个判断跳出，否则会被后面的
				质数又筛一遍，不划算 
			*/
			if(i % prime[j] == 0) break;
		}
	}
}

int main() {
	cin >> n;
	Linear(n);
	cout << cnt << endl;
	return 0;
}
