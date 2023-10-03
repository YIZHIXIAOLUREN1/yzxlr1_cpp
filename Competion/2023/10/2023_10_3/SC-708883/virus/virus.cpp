#include<bits/stdc++.h>
using namespace std;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const int N=1e6+7;
int n,m;
int w[N*4],laz[N*4];
int ll[N],rr[N],kk[N];

void maketag(int u,int x){
    laz[u]+=x;
    w[u]+=x;
}
void pushdown(int u){
    maketag(ls,laz[u]);
    maketag(rs,laz[u]);
    laz[u]=0;
}
void pushup(int u){w[u]=max(w[ls],w[rs]);}
void change(int u,int l,int r,int L,int R,int x){
    if(L>R)return;
    if(l>R||r<L)return;
    if(l>=L&&r<=R){maketag(u,x);return;}
    pushdown(u);
    change(ls,l,mid,L,R,x);
    change(rs,mid+1,r,L,R,x);
    pushup(u);
}
int query(int u,int l,int r,int L,int R){
    if(R<L)return 0;
    if(r<L||l>R)return 0;
    if(l>=L&&r<=R)return w[u];
    pushdown(u);
    return max(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("virus.in","r",stdin);
    freopen("virus.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> ll[i] >> rr[i] >> kk[i];
        change(1,1,m,ll[i],rr[i],kk[i]);
    }

    for(int i=1;i<=n;i++){
        change(1,1,m,ll[i],rr[i],-kk[i]);
        cout<<query(1,1,m,1,m)<<"\n";
        change(1,1,m,ll[i],rr[i],kk[i]);
    }

}
