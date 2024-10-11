#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,mod=38;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int w[N*2],n,q,m,a[N],tagj[N*2],tagc[N*2];
void pushup(int u){w[u]=w[ls]+w[rs];}
void maketag(int u){
    tagc[ls]=tagc[ls]*tagc[u]%mod;
    tagc[rs]=tagc[rs]*tagc[u]%mod;
    tagj[ls]=(tagj[ls]+tagj[u])%mod;
    tagj[rs]=(tagj[rs]+tagj[u])%mod;
    tagc[u]=1,tagj[u]=0;
}
void pushdown(int u){
    w[u]=(w[u]*tagc[u]%mod+tagj[u])%mod;
    maketag(u);
}
void build(int u,int l,int r){
	tagc[u]=1;
    if(l==r){w[u]=a[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
    printf("%d %d %d:%d\n",u,l,r,w[u]);//
}

void cg(int u,int l,int r,int L,int R,int jj,int cc){
    if(l>R||r<L)return;
    pushdown(u);
    if(l>=L&&r<=R){tagc[u]=cc,tagj[u]=jj;return;}
    cg(ls,l,mid,L,R,jj,cc);
    cg(rs,mid+1,r,L,R,jj,cc);
}

int qu(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    pushdown(u);
    if(l>=L&&r<=R){return w[u];}
    return (qu(ls,l,mid,L,R)+qu(rs,mid+1,r,L,R))%mod;
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
        for(int i=1;i<=2*n;i++)cout<<i<<":"<<w[i]<<endl;//
    }
    
    return 0;
}
