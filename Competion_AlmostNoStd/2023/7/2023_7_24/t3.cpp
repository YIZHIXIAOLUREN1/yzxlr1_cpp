#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int n,m;
int a[N];
int w[N*4],ma[N*4],ll[N*4],rl[N*4];

void pushup(int u){w[u]=min(w[ls],w[rs]);ma[u]=max(ma[ls],ma[rs]);}
void build(int u,int l,int r){
    if(l==r){w[u]=ma[u]=a[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
void cg1(int u,int l,int r,int v,int x){
    if(l==r){w[u]=ma[u]=x;return;}
    if(v<=mid)cg1(ls,l,mid,v,x);
    else cg1(rs,mid+1,r,v,x);
    pushup(u);
}
int cx(int u,int l,int r,int x);
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];
    build(1,1,n);

    int last=0,x1,x2;
    char ty;
    while(m--){
        cin >> ty >> x1;
        x1^=last;
        if(ty=='Q'){
            last=cx(1,1,n,x1);
            cout << last << "\n";
        }
        else{cin >> x2;x2^=last;cg1(1,1,n,x1,x2);}
    }
}
int cx(int u,int l,int r,int x){
    if(w[u]>=x){ll[u]=rl[u]=1;return 1;}
    if(l==r||ma[u]<x){ll[u]=rl[u]=0;return 0;}
    int res=cx(ls,l,mid,x)+cx(rs,mid+1,r,x);
    ll[u]=ll[ls];
    rl[u]=rl[rs];
    if(rl[ls]==1&&ll[rs]==1)res--;
    return res;
}