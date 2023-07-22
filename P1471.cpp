#include<bits/stdc++.h>
using namespace std;
#define N 100050
#define db double
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int n,m;
db a[N];
db s1[N*4],s2[N*4];
db laz1[N*4];

void pushup(int u){
    s1[u]=s1[ls]+s1[rs];
    s2[u]=s2[ls]+s2[rs];
}

void maketag(int u,int l,int r,db jl1){
    s2[u]+=jl1*jl1*len+2*jl1*s1[u];
    s1[u]+=jl1*len;
    laz1[u]+=jl1;
}

void pushdown(int u,int l,int r){
    maketag(ls,l,mid,laz1[u]);
    maketag(rs,mid+1,r,laz1[u]);
    laz1[u]=0;
}

void build(int u,int l,int r){
    if(l==r){
        s1[u]=a[l];
        s2[u]=a[l]*a[l];
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

void cgq(int u,int l,int r,int L,int R,db x){
    if(L<=l&&r<=R){
        maketag(u,l,r,x);
        return;
    }
    if(l>R||r<L)return;
    pushdown(u,l,r);
    cgq(ls,l,mid,L,R,x);
    cgq(rs,mid+1,r,L,R,x);
    pushup(u);
}

db cx1(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return s1[u];
    }
    if(l>R||r<L)return 0;
    pushdown(u,l,r);
    return cx1(ls,l,mid,L,R)+cx1(rs,mid+1,r,L,R);
}

db cx2(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        return s2[u];
    }
    if(l>R||r<L)return 0;
    pushdown(u,l,r);
    return cx2(ls,l,mid,L,R)+cx2(rs,mid+1,r,L,R);
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)scanf("%lf",&a[i]);
    build(1,1,n);
    while(m--){
        int op,x,y;
        db k;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            scanf("%lf",&k);
            cgq(1,1,n,x,y,k);
        }else if(op==2){
            printf("%.4lf\n",cx1(1,1,n,x,y)/(y-x+1));
        }else{
            db ap=cx1(1,1,n,x,y)/(y-x+1);
            printf("%.4lf\n",cx2(1,1,n,x,y)/(y-x+1)-ap*ap);
        }
    }

}
