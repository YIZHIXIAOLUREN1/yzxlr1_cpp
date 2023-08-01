#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAXN 300000
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int mod;
int n,m;
int num[MAXN];
LL w[MAXN];
LL lazyc[MAXN],lazyh[MAXN];
int umax=0;

void pushup(const int u){w[u]=(w[ls]+w[rs])%mod;}
void maketag(int u,int l,int r,LL xh,LL xc){
	lazyc[u]=lazyc[u]*xc%mod;
	lazyh[u]=(lazyh[u]*xc+xh)%mod;
	w[u]=(w[u]*xc%mod+xh*len%mod)%mod;
}
void pushdown(int u,int l,int r){
	maketag(ls,l,mid,lazyh[u],lazyc[u]);
	maketag(rs,mid+1,r,lazyh[u],lazyc[u]);
	lazyh[u]=0;
	lazyc[u]=1;
}
void build(int u,int l,int r){
	umax++;lazyc[u]=1;
    if(l==r){w[u]=num[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
LL query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
	pushdown(u,l,r);
	return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}
void update1(int u,int l,int r,int L,int R,LL xh,LL xc){
	if(L<=l&&r<=R){maketag(u,l,r,xh,xc);return;}
	if(l>R||r<L)return;
	pushdown(u,l,r);
	update1(ls,l,mid,L,R,xh,xc);
	update1(rs,mid+1,r,L,R,xh,xc);
	pushup(u);
}

int main(){
}
