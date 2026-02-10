#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=5e5+7,nn=5e5;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int n,a[N],Q;
int b[N];
ll w[N*4],sum[N*4];

void pushup(const int u){w[u]=(w[ls]+w[rs]);sum[u]=(sum[ls]+sum[rs]);}
void build(int u,int l,int r){
    if(l==r){w[u]=b[l],sum[u]=l*b[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
pair<int,int> query(int u,int l,int r,int L,int R){
    if(L>R)return {0,0};
	if(L<=l&&r<=R)return {w[u],sum[u]};
    if(l>R||r<L)return {0,0};
	pair<int,int> res1=query(ls,l,mid,L,R),res2=query(rs,mid+1,r,L,R);
    return {res1.first+res2.first,res1.second+res2.second};
}
void update1(int u,int l,int r,int tg,ll x){
	if(l==r){w[u]+=x,sum[u]+=x*l;return;}////
	if(tg<=mid)update1(ls,l,mid,tg,x);
	else update1(rs,mid+1,r,tg,x);
	pushup(u);
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        //update1(1,0,nn,a[i],1);//
    }
    build(1,0,nn);
    while(Q--){
        int ch,x,y;
        cin>>ch>>x>>y;
        if(ch==1){
            update1(1,0,nn,a[x],-1);
            update1(1,0,nn,y,1);
            a[x]=y;
        }else{
            if(y<=x){cout<<n*x<<"\n";continue;}
            //for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];//
            pair<int,int> res1=query(1,0,nn,0,x),res2=query(1,0,nn,y,nn);
            //printf("%lld %lld:%lld %lld:%lld\n",res1.first,x,res2.first,y,query(1,0,nn,x+1,y-1).second);//
            cout<<res1.first*x+res2.first*y+query(1,0,nn,x+1,y-1).second<<"\n";
        }
    }
}
