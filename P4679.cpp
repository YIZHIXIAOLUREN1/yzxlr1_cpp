#include<bits/stdc++.h>
using namespace std;
#define ls (u<<1)
#define rs ((u<<1)|1)
#define mid ((l+r)>>1)
#define len (r-l+1)
const int N=1e5+7;
int n,m;
int a[N],b[N];//0,01,10,11
vector<int> G[N];
int id[N],son[N],fa[N],siz[N],top[N],idx,d[N];

struct seg{
    bool tg,is0;
    int al,ar;
    int idl,idr;
    seg operator+(seg y)const{
        if(y.is0)return *this;
        if(is0)return y;
        seg res;
        res.idl=idl,res.idr=y.idr;
        res.al=al,res.ar=y.ar;
        if((b[idr]|b[y.idl])!=3){
            if(tg)res.al=al+y.al;
            if(y.tg)res.ar=y.ar+ar;
            if(tg&&y.tg)res.tg=1;
        }
        return res;
    }
} w[N*4],w0;

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

void pushup(int u){w[u]=w[ls]+w[rs];}

void build(int u,int l,int r){
    if(l==r){w[u].tg=1;w[u].idl=w[u].idr=l;w[u].al=w[u].ar=!(b[l]&1)+!(b[l]/2);return;}
    build(ls,l,mid);
    build(rs,mid+1,r);
    pushup(u);
}

seg query(int u,int l,int r,int L,int R){
    if(l>R||r<L)return w0;
    if(l>=L&&r<=R)return w[u];
    return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R));
}

void change(int u,int l,int r,int tg,int x){
    if(l>tg||r<tg)return;
    if(l==r){b[l]=x;w[u].al=w[u].ar=!(b[l]&1)+!(b[l]/2);return;}
    if(tg<=mid)change(ls,l,mid,tg,x);
    else change(rs,mid+1,r,tg,x);
    pushup(u);
}

seg q1(int x,int y){
    int ti=0;
    seg res1=w0,res2=w0;
    if(d[x]<d[y]){ti++;swap(x,y);swap(res1,res2);}
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]]){ti++;swap(x,y);swap(res1,res2);}
        res1=res1+query(1,1,n,id[top[x]],id[x]);
        x=fa[top[x]];
    }
    if(d[x]<d[y]){ti++;swap(x,y);swap(res1,res2);}
    res2=res2+query(1,1,n,id[y],id[x]);
    if(ti&1){ti++;swap(x,y);swap(res1,res2);}
    return res1+res2;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    w0.is0=1;
    cin >> n  >> m;
    for(int i=1,u,v;i<n;i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        a[i]=(s[0]=='#')*2+s[1]=='#';
    }
    
    dfs1(1,0);
    dfs2(1,1);

    build(1,1,n);
    while(m--){
        string s;
        cin>>s;
        if(s[0]=='Q'){
            int x,y;
            cin>>x>>y;
            seg res=q1(x,y);
            cout<<res.al<<"\n";
        }else{
            int u;
            cin>>u>>s;
            b[id[u]]=a[u]=(s[0]=='#')*2+s[1]=='#';
            change(1,1,n,id[u],a[u]);
        }
    }
}