#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define ll int
#define pr pair<int,int>
#define prr pair<int,pr>
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const ll N=3e5+7;
ll n,m;
prr ys[N];
ll a[N],b[N];
ll wa[N*4],wx[N*4],laz[N*4];
vector<pr> G[N];
int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];

void pushup(int u){wa[u]=(wa[ls]+wa[rs]);wx[u]=max(wx[ls],wx[rs]);}
void build(int u,int l,int r){
    if(l==r){wa[u]=wx[u]=b[l];return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}
ll query1(int u,int l,int r,int L,int R){
	int res=0;
    if(l>R||r<L)res=0;
    else if(l>=L&&r<=R)res=wa[u];
    else res=(query1(ls,l,mid,L,R)+query1(rs,mid+1,r,L,R));
    //printf("q:%d %d %d:%d %d:%d\n",u,l,r,L,R,res);//
    return res;
}
ll query2(int u,int l,int r,int L,int R){
    if(l>R||r<L)return 0;
    if(l>=L&&r<=R)return wx[u];
    return max(query2(ls,l,mid,L,R),query2(rs,mid+1,r,L,R));
}

void dfs1(int u,int fas){
    fa[u]=fas;
    siz[u]=1;
    d[u]=d[fas]+1;
    int ms=0;
    for(auto ii:G[u]){
        int v=ii.first,w=ii.second;
        if(v==fas)continue;
        a[v]=w;
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
    for(auto ii:G[u]){
        int v=ii.first,w=ii.second;
        if(v==fa[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

ll q1(int x,int y){
    ll res=0;
    if(d[x]<d[y])swap(x,y);
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        res=(res+query1(1,1,n,id[top[x]],id[x]));
        x=fa[top[x]];
        
    }
    if(d[x]<d[y])swap(x,y);
    res=(res+query1(1,1,n,id[y],id[x]));
    res-=2*a[y];
    return res;
}

ll q2(int x,int y){
    ll res=0;
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
int bd[10];
bool cmp1(int x,int y){return d[x]>d[y];}
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1,u,v,w;i<n;i++){
        cin >> u >> v >> w;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    dfs1(1,0);
    dfs2(1,1);
    build(1,1,n);
    for(int i=1;i<=n;i++){
    	printf("%d:%d %d %d:%d %d\n",i,fa[i],son[i],siz[i],top[i],id[i]);//
    }
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        ys[i].second.first=u;
        ys[i].second.second=v;
        ys[i].first=q1(u,v);
        printf("%d:%d %d:%d\n",i,u,v,ys[i].first);//
    }
    sort(ys+1,ys+m+1,cmp);
    int ans=ys[1].first-q2(ys[1].second.first,ys[1].second.first);
    int u=ys[1].second.first,v=ys[1].second.second;
    for(int i=2;i<=m;i++){
        int x=ys[i].second.first,y=ys[i].second.second;
        if(id[x]>id[y])swap(x,y);
        if(id[u]>id[v])swap(u,v);
        int uu=LCA(u,x);
        int vv=LCA(uu,v),v1=LCA(uu,y),v2=LCA(v,y);
        if(d[vv]<d[v1])vv=v1;
        if(d[vv]<d[v2])vv=v2;
        u=uu,v=vv;
        int res=q2(uu,vv);
        if(ys[1].first-res>=ys[i+1].first){
            ans=min(ans,ys[1].first-res);
            break;
        }
        ans=min(ans,ys[i+1].first);
    }
    cout << ans;
}