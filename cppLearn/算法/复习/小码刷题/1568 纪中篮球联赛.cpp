#include<iostream>
#include<cstdio>
using namespace std;

int n, p[1001], a[1001], b[1001];
int fa = 0, fb = 0;
int a1, a2, b1, b2;
int ansa1 = 0, ansa2 = 0, ansb1 = 0, ansb2 = 0;
int main() {
	cin >> n;
	char ch;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> a[i];
		cin >> ch;
		cin >> b[i];
	}
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] == 1) {
			fa++;
		}
		else if (p[i] == 2) {
			fb++;
		}
		if (flag == 1) {
			if (fb > fa) {
				flag = 2;
				ansa1 += (a[i] - a1);
				ansa2 += (b[i] - a2);
				b1 = a[i];
				b2 = b[i];
				a1 = 0;
				a2 = 0;
			}
			else if (fb == fa) {
				flag = 0;
				ansa1 += (a[i] - a1);
				ansa2 += (b[i] - a2);
				a1 = 0;
				a2 = 0;
			}
		}
		else if (flag == 2) {
			if (fa > fb) {
				flag = 1;
				ansb1 += (a[i] - b1);
				ansb2 += (b[i] - b2);
				b1 = 0;
				b2 = 0;
				a1 = a[i];
				a2 = b[i];
			}
			else if (fb == fa) {
				flag = 0;
				ansb1 += (a[i] - b1);
				ansb2 += (b[i] - b2);
				b1 = 0;
				b2 = 0;
			}
		}
		else if (flag == 0) {
			if (fa > fb) {
				a1 = a[i];
				a2 = b[i];
			}
			else {
				b1 = a[i];
				b2 = b[i];
			}
		}
		if (fa > fb)flag = 1;
		else if (fb > fa)flag = 2;
		else flag = 0;
		ansa1 += (ansa2 / 60);
		ansb1 += (ansb2 / 60);
		ansa2 = ansa2 % 60;
		ansb2 = ansb2 % 60;
	}
	if (a1 || a2) {
		ansa1 += (47 - a1);
		ansa2 += (60 - a2);
	}
	if (b1 || b2) {
		ansb1 += (47 - b1);
		ansb2 += (60 - b2);
	}
	ansa1 += (ansa2 / 60);
	ansb1 += (ansb2 / 60);
	ansa2 = ansa2 % 60;
	ansb2 = ansb2 % 60;
	if (ansb2 < 0) {
		ansb1--;
		ansb2 = 60 + ansb2;
	}
	if (ansa2 < 0) {
		ansa1--;
		ansa2 = 60 + ansa2;
	}
	printf("%02d:%02d\n", ansa1, ansa2);
	printf("%02d:%02d", ansb1, ansb2);
	return 0;
}