#include<bits/stdc++.h>
using namespace std;
#define N 1000050
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
int n,m;
int a[N],la[N],as[N];
int w[N*4];
struct node{
    int ty,L,R;
    friend bool operator < (const node x,const node y){
        if(y.R!=x.R)return x.R<y.R;
        return x.L<y.L;
    }
}qs[N];
int ans[N];

void pushup(int u){
    w[u]=w[ls]+w[rs];
}
void cg1(int u,int l,int r,int v,int x){
    if(v<l||v>r)return;
    if(l==r){
        w[u]=x;return;
    }
    if(v<=mid)cg1(ls,l,mid,v,x);
    else cg1(rs,mid+1,r,v,x);
    pushup(u);
}
int cx(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R)return w[u];
    if(L>r||l>R)return 0;
    return cx(ls,l,mid,L,R)+cx(rs,mid+1,r,L,R);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        la[i]=as[a[i]];
        as[a[i]]=i;
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> qs[i].L >> qs[i].R;
        qs[i].ty=i;
    }
    sort(qs+1,qs+m+1);
    int h=0;
    for(int i=1;i<=m;i++){
        while(h<qs[i].R){
            cg1(1,1,n,++h,1);
            cg1(1,1,n,la[h],0);
        }
        ans[qs[i].ty]=cx(1,1,n,qs[i].L,qs[i].R);
    }
    for(int i=1;i<=m;i++)cout << ans[i] << "\n";
}
