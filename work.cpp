#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const ll N=5e5+7;
ll n,m,rent,mod;
ll a[N],b[N];
ll w[N*4],laz[N*4];
vector<int> G[N];
int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];

void dfs1(int u,int fas){
    fa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    int ms=0;
    for(auto v:G[u]){
        if(v==fas)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>ms)ms=siz[v],son[u]=v;
    }
}

void dfs2(int u,int tof){
    id[u]=++idx;
    b[idx]=a[u];
    top[u]=tof;
    if(siz[u]==1)return;
    dfs2(son[u],tof);
    for(auto v:G[u]){
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]){
			swap(x,y);
		}
		x=fa[top[x]];
	}
	return (d[x]<d[y])?x:y;
}

void pushup(int u){w[u]=(w[ls]+w[rs])%mod;}
void maketag(int u,int l,int r,ll x){w[u]=(w[u]+x*len)%mod;laz[u]+=x;}
void pushdown(int u,int l,int r){
    maketag(ls,l,mid,laz[u]);
    maketag(rs,mid+1,r,laz[u]);
    laz[u]=0;
}

void build(int u,int l,int r){
    if(l==r){w[u]=b[l]%mod;return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

ll query(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R)return w[u];
    pushdown(u,l,r);
    return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R))%mod;
}

void change(int u,int l,int r,int L,int R,ll x){
    if(l>R||r<L)return;
    if(l>=L&&r<=R){maketag(u,l,r,x);return;}
    pushdown(u,l,r);
    change(ls,l,mid,L,R,x);
    change(rs,mid+1,r,L,R,x);
    pushup(u);
}

ll q1(int x,int y){
    ll res=0;
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        res=(res+query(1,1,n,id[top[x]],id[x]))%mod;
        x=fa[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    res=(res+query(1,1,n,id[y],id[x]))%mod;
    return res;
}

void cg1(int x,int y,ll v){
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        change(1,1,n,id[top[x]],id[x],v);
        x=fa[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    change(1,1,n,id[y],id[x],v);
}
ll qz(int x){
    return query(1,1,n,id[x],id[x]+siz[x]-1);
}
void cz(int x,ll v){
    change(1,1,n,id[x],id[x]+siz[x]-1,v);
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> rent;
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(rent,0);
    dfs2(rent,rent);
    while(m--){
        int x,y;
        cin >> x >> y;
        cout << LCA(x,y)<<"\n";
    }
}