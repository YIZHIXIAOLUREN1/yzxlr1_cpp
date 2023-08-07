#include<bits/stdc++.h>
using namespace std;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
const int N=2e5+7,K=450;
int n,Q;
int a[N],laz[N*4],w[N*4],b[N],c[K][2],k;
int ans[N];

void cl(int u,int l,int r){
    w[u]=laz[u]=0;
    if(l==r)return;
    cl(ls,l,mid);
    cl(rs,mid+1,r);
}

void mg(int u,int l,int r,int x){
    if(l==r)w[u]+=x;
    laz[u]=x;
}

void pushdown(int u,int l,int r){
    mg(ls,l,mid,laz[u]);
    mg(rs,mid+1,r,laz[u]);
    laz[u]=0;
}

void change(int u,int l,int r,int L,int R,int x){
    if(l>R||r<L)return;
    if(l>=L&&r<=R){
        mg(u,l,r,x);
        return;
    }
    pushdown(u,l,r);
    change(ls,l,mid,L,R,x);
    change(rs,mid+1,r,L,R,x);
}

int query1(int u,int l,int r,int x){
    if(l==r)return w[l];
    pushdown(u,l,r);
    if(x<=mid) return query1(ls,l,mid,x);
    else return query1(rs,mid+1,r,x);
}

int cx(int x){
    int res=b[x];
    for(int i=1;i<=k;i++){
        if(c[i][0]>res)continue;
        if(c[i][1]>=res)res+=n-c[i][1];
        else res+=c[i][0]-c[i][1]-1;
    }
    return res;
}

void ud();

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> Q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        b[a[i]]=i;
    }
    k=0;
    while(Q--){
        k++;
        int x1,x2;
        cin >> x1 >> x2;
        x1=c[k][0]=cx(x1),x2=c[k][1]=cx(x2);
        change(1,1,n,x1,x2,n-x2);
        change(1,1,n,x2+1,n,x1-x2-1);
        if(k>=445)ud();
    }
    ud();
    for(int i=1;i<=n;i++)
}

void ud(){
    for(int i=1;i<=n;i++){
        int t=query1(1,1,n,i)+i;
        b[ans[t]=a[i]]=t;
    }
    memcpy(a,ans,n*4+4);
    cl(1,1,n);
    k=0;
}