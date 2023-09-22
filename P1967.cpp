#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int,int>
#define prr pair<int,pr>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=5e4+7;
int n,m,Q;
int s[N],t[N];
int b[N];
ll w[N*4];
vector<pr> G[N],Gi[N];

int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];

void dfs1(int u,int fas){
    fa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    int ms=0;
    for(auto ii:G[u]){
        int v=ii.first;
        if(v==fas)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>ms)ms=siz[v],son[u]=v;
    }
}

void dfs2(int u,int tof){
    top[u]=tof;
    if(siz[u]==1)return;
    dfs2(son[u],tof);
    for(auto ii:G[u]){
        int v=ii.first,w=ii.second;
        if(v==fa[u]||v==son[u])continue;
        id[v]=++idx;
        b[idx]=w;
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
void pushup(int u){w[u]=(w[ls]+w[rs]);}

void build(int u,int l,int r){
    if(l==r){w[u]=b[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

ll query(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R)return w[u];
    return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R));
}

prr gg[N];
int fa[N];
bool cmp(prr x,prr y){return x.first>y.first;}

int find(int x){
    if(fa[x]==fa[fa[x]])return x;
    return fa[x]=find(fa[x]);
}

void kru(){
    sort(gg+1,gg+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=gg[i].second.first,v=gg[i].second.second;
        int w=gg[i].first;
        if(find(u)==find(v))continue;
        Gi[u].push_back({v,w});
        Gi[v].push_back({u,w});
        fa[u]=v;
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v,w;i<=m;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
        gg[i]={w,{u,v}};
    }
    kru();
    
    return 0;
}
