#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
#define N 300000
int n,m;
int num[N];
ll w[N*4];

void pushup(const int u){w[u]=(w[ls]+w[rs]);}
void build(int u,int l,int r){
    if(l==r){w[u]=num[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
	if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
	return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R));
}
void update1(int u,int l,int r,int L,int R,ll xh,ll xc){
	if(L<=l&&r<=R){/**/;return;}////
	if(l>R||r<L)return;
	update1(ls,l,mid,L,R,xh,xc);
	update1(rs,mid+1,r,L,R,xh,xc);
	pushup(u);
}