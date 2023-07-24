#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int n,m;
int a[N];
int w[N*4];
int laz[N*4];

void pushup(int u){
    w[u]=w[ls]+w[rs];
}

void maketag(int u,int l,int r,int x){
    w[u]+=x*len;
    laz[u]+=x;
}

void pushdown(int u,int l,int r){
    maketag(ls,l,mid,laz[u]);
    maketag(rs,mid+1,r,laz[u]);
    laz[u]=0;
}

void cgq(int u,int l,int r,int L,int R,int x){
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

int cx1(int u,int l,int r,int v){
	if(l==r)return w[u];
    pushdown(u,l,r);
    if(v<=mid)return cx1(ls,l,mid,v);
    else return cx1(rs,mid+1,r,v);
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]>a[i-1]){
            cgq(1,1,N,a[i],a[i-1]+1,1);
        }
    }
	for(int i=1;i<=10;i++)cout << cx1(1,1,N,i) << ":\n";//
    int last=0,x1,x2;
    char ty;
    while(m--){
        cin >> ty >> x1;
        x1^=last;
        if(ty=='Q'){
            last=cx1(1,1,N,x1);
            cout << last << "\n";
        }
        else{
            cin >> x2;
            x2^=last;
            if(a[x1]>a[x1-1]){
                cgq(1,1,N,a[x1],a[x1-1]+1,-1);
            }
            if(a[x1+1]>a[x1]){
                cgq(1,1,N,a[x1+1],a[x1]+1,-1);
            }
            a[x1]=x2;
            if(a[x1]>a[x1-1]){
                cgq(1,1,N,a[x1],a[x1-1]+1,1);
            }
            if(a[x1+1]>a[x1]){
                cgq(1,1,N,a[x1+1],a[x1]+1,1);
            }
        }
    }
}