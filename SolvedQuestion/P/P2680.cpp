#include<bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define prr pair<int,pr>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=3e5+7;
int n,m;
prr ys[N];
int a[N],b[N];
int wa[N*4],wx[N*4],laz[N*4];
vector<pr> G[N];
int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];
int res;

void pushup(int u){wa[u]=(wa[ls]+wa[rs]);wx[u]=max(wx[ls],wx[rs]);}
void build(int u,int l,int r){
    if(l==r){wa[u]=wx[u]=b[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
int query1(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R)return wa[u];
    return (query1(ls,l,mid,L,R)+query1(rs,mid+1,r,L,R));
}
int query2(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R)return wx[u];
    return max(query2(ls,l,mid,L,R),query2(rs,mid+1,r,L,R));
}

void dfs1(int u,int fas){
    fa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    for(auto ii:G[u]){
        int v=ii.first,w=ii.second;
        if(v==fas)continue;
        a[v]=w;
        dfs1(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}

void dfs2(int u,int tof){
    id[u]=++idx;
    b[idx]=a[u];
    top[u]=tof;
    if(siz[u]==1)return;
    dfs2(son[u],tof);
    for(auto ii:G[u]){
        int v=ii.first;
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int q1(int x,int y){
    res=0;
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        res=(res+query1(1,1,n,id[top[x]],id[x]));
        x=fa[top[x]];
        
    }
    if(d[x]<d[y])swap(x,y);
    res=(res+query1(1,1,n,id[y],id[x]));
    res-=a[y];
    return res;
}

int q2(int x,int y){
    res=0;
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        if(top[fa[top[x]]]!=top[y])res=max(res,query2(1,1,n,id[top[x]],id[x]));
        else res=max(res,query2(1,1,n,id[son[top[x]]],id[x]));
        x=fa[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    res=max(res,query2(1,1,n,id[son[y]],id[x]));
    return res;
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

bool cmp(prr x,prr y){return x.first>y.first;}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v,w;i<n;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        ys[i].second.first=u;
        ys[i].second.second=v;
        ys[i].first=q1(u,v);
    }
    sort(ys+1,ys+m+1,cmp);
    int ans=ys[1].first-q2(ys[1].second.first,ys[1].second.second);
    ans=max(ans,ys[2].first);
    int u=ys[1].second.first,v=ys[1].second.second;
    for(int i=2;i<=m;i++){
        int x=ys[i].second.first,y=ys[i].second.second;
        if(id[x]<id[y]&&id[y]<=id[x]+siz[x]-1)swap(x,y);
        if(id[x]>id[y]&&id[x]>id[y]+siz[y]-1)swap(x,y);
        if(id[u]<id[v]&&id[v]<=id[u]+siz[u]-1)swap(u,v);
        if(id[u]>id[v]&&id[u]>id[v]+siz[v]-1)swap(x,y);
        int uu=LCA(u,x);
        int vv=LCA(uu,v),v1=LCA(uu,y),v2=LCA(v,y);
        if(d[vv]<d[v1])vv=v1;
        if(d[vv]<d[v2])vv=v2;
        res=q2(uu,vv);
        u=uu,v=vv;
        if(ys[1].first-res>=ys[i+1].first){
            ans=min(ans,ys[1].first-res);
            break;
        }
        ans=min(ans,ys[i+1].first);
    }
    cout << ans;
}