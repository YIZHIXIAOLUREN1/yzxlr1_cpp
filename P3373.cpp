#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+7,mod=571373;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int w[N*4],n,q,m,a[N],tagj[N*4],tagc[N*4];
inline void pushup(int u){w[u]=w[ls]+w[rs];}
inline void maketag(int u,int l,int r,int cc,int jj){
    w[u]=(w[u]*cc+jj*len)%mod;
    tagc[u]=tagc[u]*cc%mod;
    tagj[u]=(tagj[u]*cc+jj)%mod;
}
inline void pushdown(int u,int l,int r){
	if(l!=r){
		maketag(ls,l,mid,tagc[u],tagj[u]);
    	maketag(rs,mid+1,r,tagc[u],tagj[u]);
	}
	tagc[u]=1,tagj[u]=0;
}
void build(int u,int l,int r){
	tagc[u]=1;tagj[u]=0;
    if(l==r){w[u]=a[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

void cg(int u,int l,int r,int L,int R,int jj,int cc){
    if(l>R||r<L)return;
    if(l>=L&&r<=R){maketag(u,l,r,cc,jj);return;}
    pushdown(u,l,r);
    cg(ls,l,mid,L,R,jj,cc);
    cg(rs,mid+1,r,L,R,jj,cc);
    pushup(u);
}

int qu(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    pushdown(u,l,r);
    if(l>=L&&r<=R){return w[u];}
    return (qu(ls,l,mid,L,R)+qu(rs,mid+1,r,L,R))%mod;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> q >> m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    while(q--){
        int ch,x,y,k;
        cin >> ch >> x >> y;
        if(ch==1){
            cin >> k;
            cg(1,1,n,x,y,0,k);
        }else if(ch==2){
            cin >> k;
            cg(1,1,n,x,y,k,1);
        }else{
            cout<<qu(1,1,n,x,y)<<endl;
        }
    }
    
    return 0;
}
