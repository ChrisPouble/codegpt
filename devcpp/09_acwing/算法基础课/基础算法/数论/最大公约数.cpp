#include <bits/stdc++.h>
using namespace std;

int n;
int gcd(int a, int b) {
	if(b == 0) return a; //0和a的最大公约数是a 
	return gcd(b, a % b); //套公式 
}

int main() {
	scanf("%d", &n);
	while(n--) {
		int a, b; 
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b)); 
	}
	return 0;
}
