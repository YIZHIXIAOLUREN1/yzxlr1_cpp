#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pr pair<int,int>
#define prr pair<int,pr>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const ll N=5e4+7,inf=0x3f3f3f3f;
int n,m,Q;
int s[N],t[N];
int b[N];
ll w[N*4];
vector<pr> G[N],Gi[N];

int id[N],son[N],ffa[N],siz[N],top[N],idx,d[N];

void dfs1(int u,int fas){
    ffa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    int ms=0;
    for(auto ii:Gi[u]){
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
    for(auto ii:Gi[u]){
        int v=ii.first,w=ii.second;
        if(v==ffa[u]||v==son[u])continue;
        id[v]=++idx;
        b[idx]=w;
        dfs2(v,v);
    }
}

void pushup(int u){w[u]=min(w[ls],w[rs]);}

void build(int u,int l,int r){
    if(l==r){w[u]=b[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

ll query(int u,int l,int r,int L,int R){
    if(l>R||r<L)return inf;
    if(l>=L&&r<=R)return w[u];
    return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}

ll LCA(int x,int y){
    ll res=inf;
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]){
			swap(x,y);
		}
        res=min(res,query(1,1,n,id[top[x]],id[x]));
		x=ffa[top[x]];
	}
	if(d[x]<d[y])swap(x,y);
    res=min(res,query(1,1,n,son[id[y]],id[x]));
    return res;
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
    for(int i=1;i<=n;i++){
        if(!siz[i]){
            dfs1(i,0);
            dfs2(i,i);
        }
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        if(find(s[i])!=find(t[i])){cout<<"-1\n";continue;}
        cout<<LCA(s[i],t[i])<<"\n";
    }
    return 0;
}
