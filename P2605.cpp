#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls (u<<1)
#define rs ((u<<1)+1)
#define mid ((l+r)>>1)
const int N=40100,inf=1e15;
int tr[N*2],laz[N*2],n,k,d[N],c[N],s[N],w[N];
int f[N];
struct edge{
	int to,nxt;
}e[N*2];
int head[N*5],cnt;

void add(int from,int to) {
    cnt++;
    e[cnt].nxt=head[from];
    e[cnt].to=to;
    head[from]=cnt;
}

void pushup(int u){
	tr[u]=min(tr[ls],tr[rs]);
}
void pushdown(int u){
	if(laz[u]==0)return;
	tr[ls]+=laz[u];tr[rs]+=laz[u];
	laz[ls]+=laz[u];laz[rs]+=laz[u];
	laz[u]=0;
}
void build(int u,int l,int r){
	laz[u]=0;
	if(l==r){
		tr[u]=f[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(u);
}
void change(int u,int l,int r,int L,int R,int p){
	if(L>R) return;
	if(l>=L&&r<=R){
		tr[u]+=p;
		laz[u]+=p;
		return;
	}
	pushdown(u);
	if(L<=mid) change(ls,l,mid,L,R,p);
	if(R>mid) change(rs,mid+1,r,L,R,p);
	pushup(u);
}
int query(int u,int l,int r,int L,int R){
	if(L>R) return inf;
	if(l>=L&&r<=R) return tr[u];
	pushdown(u);
	int res=inf;
	if(L<=mid)res=min(query(ls,l,mid,L,R),res);
	if(R>mid)res=min(query(rs,mid+1,r,L,R),res);
	return res;
}
int re[N],le[N];

signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=2;i<=n;i++)scanf("%lld",&d[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
	n++;k++;
	d[n]=w[n]=inf;
	for(int i=1;i<=n;i++){
		le[i]=lower_bound(d+1,d+n+1,d[i]-s[i])-d;
		re[i]=lower_bound(d+1,d+n+1,d[i]+s[i])-d;
		if(d[re[i]]>d[i]+s[i])re[i]--;
		add(re[i],i);
	}
	
	int no=0;
	for(int i=1;i<=n;i++){
		f[i]=no+c[i];
		for(int j=head[i];j;j=e[j].nxt){
			int v=e[j].to;
			no+=w[v];
		}
	}
	int res=f[n];
	
	for(int h=2;h<=k;h++){
		build(1,1,n);
		for(int i=1;i<=n;i++){
			f[i]=query(1,1,n,1,i-1)+c[i];
			for(int kk=head[i];kk;kk=e[kk].nxt){
				int v=e[kk].to;
				change(1,1,n,1,le[v]-1,w[v]);
			}
		}
		res=min(res,f[n]);
	}
	printf("%lld\n",res);
	return 0;
}