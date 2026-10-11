#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)

mt19937 ra(time(0));
void solve(){
	freopen("hackin.in","w",stdout);
	const int N=1e5,M=1e5,inf=(int)1e9,inff=1e8;
	cout<<N<<" "<<M<<'\n';
	rep(i,1,N/2) cout<<1<<" "<<inff<<" "<<inf<<'\n';
	rep(i,1,N/2) cout<<ra()%inf<<" "<<ra()%inf<<" "<<ra()%inff;
	rep(i,1,M-1) cout<<ra()%inf<<" "<<ra()%inf<<'\n';
	cout<<1<<" "<<inff;
}
int main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	solve();
}