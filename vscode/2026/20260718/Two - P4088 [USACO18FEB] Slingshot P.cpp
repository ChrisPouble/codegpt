#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

#define per(i,r,l) for(int i=(r);i>=(l);--i)


const int N=1e5+5,M=1e6+5;
const ll inf=2e9;
struct node{ll x,y;ll t;}a[N],q[N];
ll n,m;
struct BIT{
	ll t[M],b[M],m;
	void clear(){memset(t,0x3f,sizeof t);}
	void init(){
		sort(b+1,b+1+m);
		m=unique(b+1,b+1+m)-(&b[1]);
	}
	void up(ll x,ll z){
		x=lower_bound(b+1,b+1+m,x)-b; 
		for(;x<=m;x+=x&-x) t[x]=min(t[x],z);
	}
	ll get(ll x){
		x=lower_bound(b+1,b+1+m,x)-b; 
		ll res=t[0];for(;x;x-=x&-x)res=min(res,t[x]);return res;
	}
}T[2];
ll ans[N];
void solve(){
    freopen("hackin.in", "r", stdin);
    freopen("rightout.out", "w", stdout);
	T[0].clear(),T[1].clear();
	cin>>n>>m;
	rep(i,1,n)cin>>a[i].x>>a[i].y>>a[i].t,T[0].b[++T[0].m]=a[i].y,T[1].b[++T[1].m]=inf-a[i].y+1;
	
	sort(a+1,a+1+n,[](node q,node w){return q.x<w.x;});
	rep(i,1,m) cin>>q[i].x>>q[i].y,q[i].t=i,ans[i]=abs(q[i].x-q[i].y);
	rep(i,1,m) T[0].b[++T[0].m]=q[i].y,T[1].b[++T[1].m]=inf-q[i].y+1;
	T[0].init(),T[1].init();
	sort(q+1,q+1+m,[](node qq,node qw){return qq.x<qw.x;});
	int now=1;
	rep(i,1,m){
		while(now<=n&&a[now].x<=q[i].x){
			T[0].up(a[now].y,-(a[now].x+a[now].y)+a[now].t);
			T[1].up(inf-a[now].y+1,-(a[now].x-a[now].y)+a[now].t);
			now++;
		}
		ans[q[i].t]=min({ans[q[i].t],q[i].x+q[i].y+T[0].get(q[i].y),q[i].x-q[i].y+T[1].get(inf-q[i].y+1)});
	}
	T[0].clear(),T[1].clear();
	now=n;
	per(i,m,1){
		while(now>=1&&a[now].x>=q[i].x){
			T[0].up(a[now].y,-(-a[now].x+a[now].y)+a[now].t);
			T[1].up(inf-a[now].y+1,-(-a[now].x-a[now].y)+a[now].t);
			now--;
		}
		ans[q[i].t]=min({ans[q[i].t],-q[i].x+q[i].y+T[0].get(q[i].y),-q[i].x-q[i].y+T[1].get(inf-q[i].y+1)});
	}
	rep(i,1,m) cout<<ans[i]<<'\n';
}
signed main(){
	cin.tie(0)->ios::sync_with_stdio(false);
	solve();
}