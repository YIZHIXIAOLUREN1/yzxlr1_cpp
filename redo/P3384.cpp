#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=1e5+7;
int n,m,root,mod;
ll T[N],W[N*4],tag[N*4];
int fa[N],son[N],d[N],siz[N],dfn[N],tot,ran[N],top[N];
vector<int> G[N];

void pushup(int u){W[u]=W[ls]+W[rs];}

void build(int u,int l,int r){
    if(l==r){
        W[u]=T[ran[l]]%mod;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

void maketag(int u,int l,int r,ll jj){
    W[u]=(W[u]+jj*len%mod)%mod;
    tag[u]=(tag[u]+jj)%mod;
}

void pushdown(int u,int l,int r){
    if(l>=r)return;
    maketag(ls,l,mid,tag[u]);
    maketag(rs,mid+1,r,tag[u]);
    tag[u]=0;
}

void cg(int u,int l,int r,int L,int R,ll jj){
    if(l>R||r<L)return;
    if(l>=L&&r<=R){maketag(u,l,r,jj);return;}
    pushdown(u,l,r);
    cg(ls,l,mid,L,R,jj);
    cg(rs,mid+1,r,L,R,jj);
    pushup(u);
}

ll qu(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R){return W[u];}
    pushdown(u,l,r);
    return (qu(ls,l,mid,L,R)+qu(rs,mid+1,r,L,R))%mod;
}

void dfs1(int u){
    son[u]=-1;
    siz[u]=1;
    for(auto v:G[u]){
        if(v==fa[u])continue;
        fa[v]=u;
        d[v]=d[u]+1;
        dfs1(v);
        siz[u]+=siz[v];
        if(son[u]==-1||siz[v]>siz[son[u]])son[u]=v;
    }
}

void dfs2(int u,int to){
    top[u]=to;
    dfn[u]=++tot;
    ran[tot]=u;
    if(son[u]==-1)return;
    dfs2(son[u],to);
    for(auto v:G[u]){
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int LCA(int u,int v){
    while(top[u]!=top[v]){
        if(d[top[u]]<d[top[v]])swap(u,v);
        u=fa[top[u]];
    }
    if(d[u]<d[v])swap(u,v);
    return u;
}

void cgLCA(int u,int v,ll jj){
    while(top[u]!=top[v]){
        if(d[top[u]]<d[top[v]])swap(u,v);
        cg(1,1,n,dfn[top[u]],dfn[u],jj);
        u=fa[top[u]];
    }
    if(d[u]<d[v])swap(u,v);
    cg(1,1,n,dfn[v],dfn[u],jj);
}

ll quLCA(int u,int v){
    ll res=0;
    while(top[u]!=top[v]){
        if(d[top[u]]<d[top[v]])swap(u,v);
        res=(res+qu(1,1,n,dfn[top[u]],dfn[u]))%mod;
        u=fa[top[u]];
    }
    if(d[u]<d[v])swap(u,v);
    res=(res+qu(1,1,n,dfn[v],dfn[u]))%mod;
    return res;
}

void cgs(int u,ll jj){cg(1,1,n,dfn[u],dfn[u]+siz[u]-1,jj);}
ll qus(int u){return qu(1,1,n,dfn[u],dfn[u]+siz[u]-1);}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> root >> mod;
    for(int i=1;i<=n;i++)cin >> T[i];
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    fa[root]=0,d[root]=1;
    dfs1(root);
    dfs2(root,root);
	build(1,1,n);
    while(m--){
        ll ty,x,y,z;
        cin >> ty;
        if(ty==1){
            cin >> x >> y >> z;
            cgLCA(x,y,z%mod);
        }else if(ty==2){
            cin >> x >> y;
            cout<<quLCA(x,y)<<"\n";
        }else if(ty==3){
            cin >> x >> z;
            cgs(x,z%mod);
        }else{
            cin >> x;
            cout<<qus(x)<<"\n";
        }
        //for(int i=1;i<=n;i++)cout<<qu(1,1,n,dfn[i],dfn[i])<<" \n"[i==n];//
    }
    
    return 0;
}
