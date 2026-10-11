#include <bits/stdc++.h>
using namespace std;

int n, a, b;
struct Int {
    int len, a[20010]; //高精数的长度和数字
    Int(string s) { //构造函数
        memset(a, 0, sizeof(a)); //归零
        for (int i = 1; i <= s.size(); i++) //加入数字
            a[i] = s[s.size() - i] - 48;
        len = s.size(); //加入长度
    }
    Int(){}
    int &operator[](int i) { //可以把x.a[i]变成x[i]，写起来更简便，注意要加&号
        return a[i];
    }
    void Cout() { //完结输出
        if (a[len + 1] != 0) len++; //去掉前导零
        for (int i = max(len, 1); i >= 1; i--) cout << a[i];
        cout << endl;
    }
}ans[1010];

Int operator*(Int a, int b) { //高精度乘法
    Int c("0");
    c.len = a.len + 10;
    for (int i = 1; i <= a.len; i++)
        c[i] += a[i] * b;
    for (int i = 1; i <= c.len; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while (c[c.len] == 0) c.len--;
    return c;
}

Int operator/(Int a, int b) { //高精度除法
    Int c("0");
    int d = 0;
    while (a[a.len] == 0) a.len--;
    c.len = a.len;
    for (int i = a.len; i >= 1; i--) {
    	d = d * 10 +a[i];
    	c[i] = d / b;
    	d %= b;
	}
    while (c[c.len] == 0) c.len--;
    return c;
}

bool operator<(Int a, Int b) { //高精度判断大小 
	if(a.len != b.len) return a.len < b.len;
	for (int i = 1; i <= a.len; i++)
		if(a[i] < b[i]) return true;
		else if(a[i] > b[i]) return false;
	return false;
}

struct node{
	int a, b;
}g[1010];

bool cmp1(node x, node y) {
	if(x.a * x.b == y.a * y.b) return x.b < y.b;
	return (x.a * x.b) < (y.a * y.b);
}

bool cmp2(Int x, Int y) {
	return x < y;
}

string gw() {
	int t = a, sum = 0;
	if(t == 0) sum = 1;
	while(t) {
		t /= 10;
		sum++;
	}
	string s;
	for (int i = sum - 1; i >= 0; i--)
		s += a % 10 + '0', a /= 10;
	for (int i = 0; i < s.size() / 2; i++)
		swap(s[i], s[s.size() - i - 1]);
	return s;
}

int main() {
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> g[i].a >> g[i].b;
	sort(g + 1, g + n + 1, cmp1);
	string s = gw();
	Int q(s);
	for (int i = 1; i <= n; i++) {
		ans[i] = q / g[i].b;
		q = q * g[i].a;
	}
	sort(ans + 1, ans + n + 1, cmp2);
//	Int answer("0");
//	for (int i = 1; i <= n; i++)
//		answer = answer < ans[i] ? ans[i] : answer;
	for (int i = 1; i <= n; i++)
		ans[i].Cout();
	ans[n].Cout();
    return 0;
}
