#include <bits/stdc++.h>
using namespace std;

int Q;
vector<int>v;
int main() {
	scanf("%d", &Q);
	while(Q--) {
		int opt, x; scanf("%d%d", &opt, &x);
		if(opt == 1) v.push_back(x);
		else {
			//sort(v.begin(), v.end());
			//unique(v.begin(), v.end());
			printf("%d\n", v[v.size() - x]);
		}
	}
	return 0;
}
