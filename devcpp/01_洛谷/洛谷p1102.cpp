#include <bits/stdc++.h>
using namespace std;
    
long long ans, a[20010];
int n, c;
map<int, int>m;
void binary() { //二分法 
	sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        ans += upper_bound(a + 1, a + n + 1, a[i] + c) - lower_bound(a + 1, a + n + 1, a[i] + c);
}

void ma() { //map法 
	for (int i = 1; i <= n; i++)
		m[a[i]]++;
	for (int i = 1; i <= n; i++)
		ans += m[a[i] + c];
} 

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
 	//binary();
 	ma();
    cout << ans << endl;
    return 0;
}
