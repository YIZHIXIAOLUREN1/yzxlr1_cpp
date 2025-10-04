#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
int n,Q;
int a[N];
int w[N*4];
int lazy[N*4];//0,1,2
vector<pair<int,int>> nod;

void push_up(int u){w[u]=(w[ls]+w[rs]);}
void maketag(int u,int l,int r,int tg){
    lazy[u]=tg;
    if(tg==1)w[u]=len;
    else if(tg==0)w[u]=0;
}
void pushdown(int u,int l,int r){
    maketag(ls,l,mid,lazy[u]);
    maketag(rs,mid+1,r,lazy[u]);
    lazy[u]=2;
}
void build(int u,int l,int r){
    lazy[u]=2;
    if(l==r){w[u]=1;return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    push_up(u);
}
int query(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R)return w[u];
    if(l>R||r<L)return 0;
    pushdown(u,l,r);
    return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
void update(int u,int l,int r,int L,int R,int tg){
    if(L<=l&&r<=R){maketag(u,l,r,tg);return;}
    if(l>R||r<L)return;
    pushdown(u,l,r);
    update(ls,l,mid,L,R,tg);
    update(rs,mid+1,r,L,R,tg);
    push_up(u);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>Q;
        build(1,1,n);
        nod.clear();
        for(int i=1,l=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<a[i-1]){
                nod.push_back({l,i-1});
                l=i;
            }
            if(i==n)nod.push_back({l,n});
        }
        for(int i=1;i<nod.size();i++){
            int x=nod[i].first;
        }
    }
}
