#include<bits/stdc++.h>
#define mid(l,r) (l+r)>>1
#define int long long
#define lc(a) a<<1
#define rc(a) a<<1|1
#define MAXN 1000005

#define forr(i,a,b) for(int i=a;i<=b;++i)
#define chkmax(a,b) a=a>b?a:b
#define de puts("debug");
using namespace std;
int a[MAXN],f[MAXN];
int pre[MAXN],last[MAXN];
int n,m;
typedef struct Segment_Tree{
	int les,res;
	int ans,val;
}Tree;
Tree tree[MAXN*4];
void update(int i){
	Tree l=tree[lc(i)],r=tree[rc(i)];
	tree[i].val=l.val+r.val;
	tree[i].les=max(l.les,l.val+r.les);
	tree[i].res=max(r.res,r.val+l.res);
	tree[i].ans=max(l.res+r.les,max(l.ans,r.ans));
}
void build(int i,int l,int r){
	if(l==r){
		tree[i].ans=tree[i].les=tree[i].res=tree[i].val=a[l];
		return;
	}
	int mid=mid(l,r);
	build(lc(i),l,mid);
	build(rc(i),mid+1,r);
	update(i);
}
void Change(int p,int i,int l,int r,int val){
	if(l==r){
		tree[i].ans=tree[i].les=tree[i].res=tree[i].val=val;
		return;
	}
	int mid=mid(l,r);
	if(p<=mid){
		Change(p,lc(i),l,mid,val);
	}
	else Change(p,rc(i),mid+1,r,val);
	update(i);
}
int ans;
signed main(){
	scanf("%lld%lld",&n,&m);
	forr(i,1,n){
		cin>>f[i];
	}
	forr(i,1,m){
		cin>>a[i];
	}
	forr(i,1,n){
		pre[i]=last[f[i]],last[f[i]]=i;
		if(pre[i]){
			Change(pre[i],1,1,n,-a[f[i]]);
		}
		if(pre[pre[i]]){
			Change(pre[pre[i]],1,1,n,0);
		}
		Change(i,1,1,n,a[f[i]]);
		ans=max(ans,tree[1].ans);
	}
	printf("%lld",ans);
}
